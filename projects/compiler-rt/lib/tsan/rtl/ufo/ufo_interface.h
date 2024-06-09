#ifndef UFO_UFO_RTL_H
#define UFO_UFO_RTL_H

#include "../tsan_defs.h"
#include "../tsan_flags.h"
#include "../tsan_rtl.h"
#include "defs.h"

namespace aser {
namespace ufo {
using __sanitizer::u8;
using __sanitizer::u16;
using __sanitizer::u32;
using __sanitizer::u64;
using __sanitizer::s8;
using __sanitizer::s16;
using __sanitizer::s32;
using __sanitizer::s64;
using __sanitizer::uptr;
using __sanitizer::Printf;

/**
 * why do we need ThreadBegin/ThreadEnd along with ThreadFork/ThreadJoin:
 * the tsan assigned tid may be reused, so we need to pinpoint the begin/end events in child thread too
 *
 */
enum EventType {
  ThreadBegin = 0,
  ThreadEnd,
  ThreadCreate = 2,
  ThreadJoin,
  ThreadAcqLock,
  ThreadRelLock = 5,
  MemAlloc,
  MemDealloc,
  MemRead = 8,
  MemWrite,
  MemRangeRead = 10,
  MemRangeWrite,
  PtrAssignment = 12,
  TLHeader,
  InfoPacket,
  EnterFunc = 15,
  ExitFunc,
  ThrCondWait,
  ThrCondSignal = 18,
  ThrCondBC,
  PtrDeRef = 20
};

/*
no pc on thread begin end events
 */
#pragma pack(push, 1)

// 8 + 48 + 48 + 32 -> 126
PACKED_STRUCT(AllocEvent) {
  static const u8 TYPE_INDEX = EventType::MemAlloc;
  const u8 type_index = TYPE_INDEX;
//  u64 idx: 48;
  u64 addr : 48;
  u64 pc : 48;
  u32 size;
  u64 order : 48;

  ALWAYS_INLINE
  explicit AllocEvent(u64 ad, u64 p, u32 d, u64 o)
      : addr(ad),
        pc(p),
        size(d),
        order(o){}
};
static_assert(sizeof(AllocEvent) == 23, "compact struct (align 8) not supported, please use clang 3.8.1");

// 8 + 48 + 48 + 32 -> 126 //JEFF
PACKED_STRUCT(DeallocEvent) {
  static const u8 TYPE_INDEX = EventType::MemDealloc;
  const u8 type_index = TYPE_INDEX;
//  u64 idx: 48;
  u64 addr : 48;
  u64 pc : 48;
  u32 size;//JEFF
  u64 order : 48;

  ALWAYS_INLINE
  explicit DeallocEvent(u64 h, u64 ip, u32 d, u64 o)
      : addr(h),
        pc(ip),
        size(d),
        order(o){}
};
static_assert(sizeof(DeallocEvent) == 23, "compact struct (align 8) not supported, please use clang 3.8.1");


// 8 + 48 + 48 -> 104
PACKED_STRUCT(LockEvent) {
  static const u8 TYPE_INDEX = EventType::ThreadAcqLock;
  const u8 type_index = TYPE_INDEX;
//  u64 idx: 48;
  u64 mutexId : 48;
  u64 pc : 48;
  u64 order : 48;


  ALWAYS_INLINE
  explicit LockEvent(u64 h, u64 p, u64 o)
      : mutexId(h),
        pc(p),
        order(o){}
};
static_assert(sizeof(LockEvent) == 19, "compact struct (align 8) not supported, please use clang 3.8.1");

// 8 + 48 +48 -> 104
PACKED_STRUCT(UnlockEvent) {
  static const u8 TYPE_INDEX = EventType::ThreadRelLock;
  const u8 type_index = TYPE_INDEX;
  u64 mutexId : 48;
  u64 pc : 48;
  u64 order : 48;

  ALWAYS_INLINE
  explicit UnlockEvent(u64 h, u64 ip, u64 o)
      : mutexId(h),
        pc(ip),
        order(o){ }
};
static_assert(sizeof(UnlockEvent) == 19, "compact struct (align 8) not supported, please use clang 3.8.1");


PACKED_STRUCT(ThrCondWaitEvent) {
  static const u8 TYPE_INDEX = EventType::ThrCondWait;
  const u8 type_index = TYPE_INDEX;
  u64 idx: 48;
  u64 cond: 48;
  u64 mtx: 48;
  u64 pc: 48;
  u64 order : 48;
  explicit ThrCondWaitEvent(u64 i, u64 c, u64 m, u64 p, u64 o)
      : idx(i),
        cond(c),
        mtx(m),
        pc(p),
        order(o){}
};
static_assert(sizeof(ThrCondWaitEvent) == 31, "compact struct (align 8) not supported, please use clang 3.8.1");

PACKED_STRUCT(ThrCondSignalEvent) {
  static const u8 TYPE_INDEX = EventType::ThrCondSignal;
  const u8 type_index = TYPE_INDEX;
  u64 idx: 48;
  u64 cond: 48;
  u64 pc: 48;
  u64 order : 48;
  explicit ThrCondSignalEvent(u64 i, u64 c, u64 p, u64 o)
    : idx(i),
    cond(c),
    pc(p),
    order(o){}
};
static_assert(sizeof(ThrCondSignalEvent) == 25, "compact struct (align 8) not supported, please use clang 3.8.1");

PACKED_STRUCT(ThrCondBCEvent) {
  static const u8 TYPE_INDEX = EventType::ThrCondSignal;
  const u8 type_index = TYPE_INDEX;
    u64 idx: 48;
  u64 cond: 48;
  u64 pc: 48;
  u64 order : 48;
  explicit ThrCondBCEvent(u64 i, u64 c, u64 p, u64 o)
    : idx(i),
    cond(c),
        pc(p),
     order(o){}
};
static_assert(sizeof(ThrCondBCEvent) == 25, "compact struct (align 8) not supported, please use clang 3.8.1");


// 8 + 48 + 48 + 32 = 126
PACKED_STRUCT(MemRangeAccEvent) {
  const u8 type_index;
//  u64 idx: 48;
  u64 addr : 48;
  u64 pc : 48;
  u32 size;
  u64 order : 48;
  ALWAYS_INLINE
  explicit MemRangeAccEvent(u8 ty_idx, u64 adr, u64 ip, u32 sz, u64 o)
      : type_index(ty_idx),
        addr(adr),
        pc(ip),
        size(sz),
        order(o){}
};
static_assert(sizeof(MemRangeAccEvent) == 23, "compact struct (align 8) not supported, please use clang 3.8.1");


inline void my_strncpy(char *dest, const char *src, int n) {
  int i;
  if (src == 0) {
    if (n > 0) {
      dest[0] = '\0';
    }
    return;
  }
  // 复制最多 n-1 个字符
  for (i = 0; i < n - 1 && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  // 如果src的长度小于n-1, 在目标字符串的末尾添加 '\0'
  if (i < n) {
    dest[i] = '\0';
  }

  // 如果 src 的长度大于等于 n-1, 在目标字符串的末尾添加 '\0'
  else if (i == n - 1) {
    dest[n - 1] = '\0';
  }
}

//8 + 48 + 48 -> 104 + ???
PACKED_STRUCT(MemAccEvent) {
  const u8 type_index;
  u64 addr : 48;
  u64 pc : 48;
  u64 order : 48;
  u32 line : 32;
  char file[10];

  ALWAYS_INLINE
  explicit MemAccEvent(u8 ty_idx, u64 h, u64 ip, u64 o, u64 l, char *f)
      : type_index(ty_idx), addr(h), pc(ip), order(o), line(l) {
    my_strncpy(file, f, sizeof(file));
  }
};
static_assert(sizeof(MemAccEvent) == 33, "compact struct (align 8) not supported, please use clang 3.8.1");

//8 + 16 + 48 + 32 -> 104
PACKED_STRUCT(CreateThreadEvent) {
  static const u8 TYPE_INDEX = EventType::ThreadCreate;
  const u8 type_index = TYPE_INDEX;
  u64 idx: 48;
    TidType tid_kid;
  u32 e_time; // time elapsed since program start (stored in header)
  u64 pc : 48;
  u64 order : 48;


  ALWAYS_INLINE
  explicit CreateThreadEvent(u64 i,TidType tk, u32 t, u64 ip, u64 o)
      : idx(i),
        tid_kid(tk),
        e_time(t),
        pc(ip),
        order(o){ }
};
static_assert(sizeof(CreateThreadEvent) == 25, "compact struct (align 8) not supported, please use clang 3.8.1");

//8 + 16 + 48 + 32 + (48+32+48+32)-> 33
PACKED_STRUCT(ThreadBeginEvent) {
  static const u8 TYPE_INDEX = EventType::ThreadBegin;
  const u8 type_index = TYPE_INDEX;
  TidType tid_parent;
  u64 pc : 48;
  u32 e_time; // time elapsed since program start (stored in header)
  u64 stk_addr: 48;
  u32 stk_size;
  u64 tls_addr: 48;
  u32 tls_size;
  u64 order : 48;


  ALWAYS_INLINE
  explicit ThreadBeginEvent(TidType tp, u64 p, u32 t, u64 o)
      : tid_parent(tp),
        pc(p),
        e_time(t),
        stk_addr(0),
        stk_size(0),
        tls_addr(0),
        tls_size(0),
        order(o){ }
};
static_assert(sizeof(ThreadBeginEvent) == 39, "compact struct (align 8) not supported, please use clang 3.8.1");


//8 +  16 + 32 + 48 -> 104
PACKED_STRUCT(JoinThreadEvent) {
  static const u8 TYPE_INDEX = EventType::ThreadJoin;
  const u8 type_index = TYPE_INDEX;
  u64 idx: 48;
    TidType tid_joiner;
  u32 e_time; // time elapsed since program start (stored in header)
  u64 pc : 48;
  u64 order : 48;


  ALWAYS_INLINE
  explicit JoinThreadEvent(u64 i,TidType tk, u32 time, u64 ip, u64 o)
      : idx(i),
        tid_joiner(tk),
        e_time(time),
        pc(ip),
        order(o){ }
};
static_assert(sizeof(JoinThreadEvent) == 25, "compact struct (align 8) not supported, please use clang 3.8.1");


//(8 +  16 + 32 -> 56
PACKED_STRUCT(ThreadEndEvent) {
  static const u8 TYPE_INDEX = EventType::ThreadEnd;
  const u8 type_index = TYPE_INDEX;
  TidType tid_parent;
  u32 e_time; // time elapsed since program start (stored in header)
  u64 order : 48;

  ALWAYS_INLINE
  explicit ThreadEndEvent(TidType tp, u32 t, u64 o)
      : tid_parent(tp),
        e_time(t),
        order(o)     { }
};
static_assert(sizeof(ThreadEndEvent) == 13, "compact struct (align 8) not supported, please use clang 3.8.1");


PACKED_STRUCT(PtrAssignEvent) {
  static const u8 TYPE_INDEX = EventType::PtrAssignment;
  const u8 type_index = TYPE_INDEX;
  u64 ptr_l: 48;
  u64 ptr_r: 48;
  u64 order : 48;


  ALWAYS_INLINE
  explicit PtrAssignEvent(u64 pl, u64 pr, u64 o)
      : ptr_l(pl),
        ptr_r(pr),
        order(o){ }
};
static_assert(sizeof(PtrAssignEvent) == 19, "compact struct (align 8) not supported, please use clang 3.8.1");

PACKED_STRUCT(PtrDeRefEvent) {
  static const u8 TYPE_INDEX = EventType::PtrDeRef;
  const u8 type_index = TYPE_INDEX;
  u64 ptr_addr: 48;
  u64 order : 48;

  ALWAYS_INLINE
  explicit PtrDeRefEvent(u64 pa, u64 o)
      : ptr_addr(pa),
        order(o) {}
};
static_assert(sizeof(PtrDeRefEvent) == 13, "compact struct (align 8) not supported, please use clang 3.8.1");

PACKED_STRUCT(UFOHeader) {
  static const u8 TYPE_INDEX = EventType::TLHeader;
  const u8 type_index = TYPE_INDEX;
  const u64 version = UFO_VERSION;
  const TidType tid;
  const u64 timestamp;
  const u32 length;
// data with specified length can follow
  ALWAYS_INLINE
  explicit UFOHeader(TidType curT, u64 time, u32 len)
      :  tid(curT),
         timestamp(time),
         length(len)  {}
};
static_assert(sizeof(UFOHeader) == 23, "compact struct (align 8) not supported, please use clang 3.8.1");

PACKED_STRUCT(FuncEntryEvent) {
  static const u8 TYPE_INDEX = EventType::EnterFunc;
  const u8 type_index = TYPE_INDEX;
  u64 caller_pc : 48;
  u64 order : 48;
  ALWAYS_INLINE
  explicit FuncEntryEvent(u64 pc , u64 o)
      :  caller_pc(pc),
        order(o){}
};
static_assert(sizeof(FuncEntryEvent) == 13, "compact struct (align 8) not supported, please use clang 3.8.1");

PACKED_STRUCT(FuncExitEvent) {
  static const u8 TYPE_INDEX = EventType::ExitFunc;
  const u8 type_index = TYPE_INDEX;
  u64 order : 48;

  explicit FuncExitEvent(u64 o)
      :order(o){}
};
static_assert(sizeof(FuncExitEvent) == 7, "compact struct (align 8) not supported, please use clang 3.8.1");

PACKED_STRUCT(UFOPkt) {
  static const u8 TYPE_INDEX = EventType::InfoPacket;
  const u8 type_index = TYPE_INDEX;
  const u64 timestamp;
  const u64 length; // data
// data with specified length can follow
  ALWAYS_INLINE
  explicit UFOPkt(u64 time, u64 len)
      :   timestamp(time),
          length(len)  {}
};
static_assert(sizeof(UFOPkt) == 17, "compact struct (align 8) not supported, please use clang 3.8.1");


#pragma pack(pop)

extern "C" {
//rtl/tsan_interface.cc:32:  bw::ufo_bench::init_ufo();
bool init_ufo();
//rtl/tsan_rtl.cc:383:  bw::ufo_bench::finish_ufo();
bool finish_ufo();

void *on_alloc(__tsan::ThreadState *thr, uptr pc, void *addr, uptr size);
void on_dealloc(__tsan::ThreadState *thr, uptr pc, void *addr, uptr size);

// called by parent thread
void on_thread_created(int tid_parent, int tid_kid, uptr pc);
// called by kid thread itself
void on_thread_start(__tsan::ThreadState* thr, uptr stk_addr, uptr stk_size, uptr tls_addr, uptr tls_size);

// called by main thread
void on_thread_join(int tid_main, int tid_joiner, uptr pc);
void on_thread_end(__tsan::ThreadState* thr);
    
void on_mtx_lock(__tsan::ThreadState *thr, uptr pc, u64 mutex_id);
void on_mtx_unlock(__tsan::ThreadState *thr, uptr pc, u64 mutex_id);
void on_rd_lock(__tsan::ThreadState *thr, uptr pc, u64 mutex_id);
void on_rd_unlock(__tsan::ThreadState *thr, uptr pc, u64 mutex_id);
void on_rw_unlock(__tsan::ThreadState *thr, uptr pc, u64 mutex_id);

void on_cond_wait(__tsan::ThreadState* thr, uptr pc, u64 addr_cond, u64 addr_mtx);
void on_cond_signal(__tsan::ThreadState* thr, uptr pc, u64 addr_cond);
void on_cond_broadcast(__tsan::ThreadState* thr, uptr pc, u64 addr_cond);

//void MemoryAccess(ThreadState *thr, uptr pc, uptr addr,
//                  int kAccessSizeLog, bool kAccessIsWrite, bool kIsAtomic) {
void on_mem_acc(__tsan::ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog, bool is_write);
void on_mem_acc_line(__tsan::ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog, bool is_write, u32 line, char *file);

void on_mem_range_acc(__tsan::ThreadState *thr, uptr pc, uptr addr, uptr size, bool is_write);

void enter_func(__tsan::ThreadState *thr, uptr pc);
void exit_func(__tsan::ThreadState *thr);


void on_ptr_deref(__tsan::ThreadState *thr, uptr pc, uptr addr_ptr);
void on_ptr_prop(__tsan::ThreadState *thr, uptr pc, uptr addr_src, uptr addr_dest);

void before_fork();
void parent_after_fork();
void child_after_fork();

} //extern "C"


} // ns ufo_bench
} // ns bw

#endif //UFO_UFO_RTL_H


