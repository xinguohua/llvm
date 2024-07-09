
#ifndef UFO_RTL_IMPL_H
#error "error: must be included by rtl_impl.h"
#endif

#ifdef STAT_ON

#define __MC_STAT                              \
  if (is_write) {                              \
    uctx->stat[tid].c_write[kAccessSizeLog]++; \
  } else {                                     \
    uctx->stat[tid].c_read[kAccessSizeLog]++;  \
  }

#else

#define __MC_STAT

#endif

__HOT_CODE
void impl_mem_acc(ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog,
                  bool is_write) {
  if (is_write) {
    DPrintf5("impl_mem_accUFO>>> #%d write %d bytes to %p  val:%p   pc:%p\r\n",
             thr->tid, (1 << kAccessSizeLog), addr,
             __read_addr(addr, kAccessSizeLog), pc);
  } else {
    DPrintf5("impl_mem_accUFO>>> #%d read %d bytes from %p val:%p   pc:%p\r\n",
             thr->tid, (1 << kAccessSizeLog), addr,
             __read_addr(addr, kAccessSizeLog), pc);
  }

  int tid = thr->tid;
  __MC_STAT

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;

#ifndef BUF_EVENT_ON

  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, (u64)addr, (u64)pc, (u64)(__sync_fetch_and_add(&uctx->order, 1), 0, 0);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  const int acc_len = 1 << kAccessSizeLog;
  internal_write(fd, addr, acc_len)
#else

  auto &buf = uctx->tlbufs[tid];
  const int acc_len = 1 << kAccessSizeLog;
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)), 0,
                            0));
  Byte *ptr = (Byte *)addr;
  for (int i = 0; i < acc_len; ++i) {
    *(buf.buf_ + buf.size_ + i) = *(ptr + i);
  }
  buf.size_ += acc_len;
#endif
}

__HOT_CODE
void impl_mem_acc_line(ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog,
                       bool is_write, u32 line, char *file) {
  if (is_write) {
    DPrintf5(
        "impl_mem_acc_lineUFO>>> #%d write %d bytes to %p  val:%p   pc:%p, line:%d "
        "file: %s \r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  } else {
    DPrintf5(
        "impl_mem_acc_lineUFO>>> #%d read %d bytes from %p val:%p   pc:%p, line:%d "
        "file: %s \r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  }
  int tid = thr->tid;
  __MC_STAT

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;
#ifndef BUF_EVENT_ON

  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, (u64)addr, (u64)pc, (u64)(__sync_fetch_and_add(&uctx->order, 1), 0, 0);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  const int acc_len = 1 << kAccessSizeLog;
  internal_write(fd, addr, acc_len)
#else

  auto &buf = uctx->tlbufs[tid];
  const int acc_len = 1 << kAccessSizeLog;
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)),
                            (u32)line, (char *)file));
  Byte *ptr = (Byte *)addr;
  for (int i = 0; i < acc_len; ++i) {
    *(buf.buf_ + buf.size_ + i) = *(ptr + i);
  }
  buf.size_ += acc_len;
#endif
}

// no value
__HOT_CODE
void impl_mem_acc_nv(ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog,
                     bool is_write) {
  if (is_write) {
    DPrintf5(
        "impl_mem_acc_nvUFO>>> #%d write %d bytes to %p  val:%p   pc:%p\r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc);
  } else {
    DPrintf5(
        "impl_mem_acc_nvUFO>>> #%d read %d bytes from %p val:%p   pc:%p\r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc);
  }

  int tid = thr->tid;
  __MC_STAT

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;

#ifndef BUF_EVENT_ON
  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, _idx, (u64)addr, (u64)pc, (u64)(__sync_fetch_and_add(&uctx->order, 1), 0, 0);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  return;
#else
  auto &buf = uctx->tlbufs[tid];
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)), 0,
                            0));
  return;
#endif
}

__HOT_CODE
void impl_mem_acc_line_nv(ThreadState *thr, uptr pc, uptr addr,
                          int kAccessSizeLog, bool is_write, u32 line,
                          char *file) {
  if (is_write) {
    DPrintf5(
        "impl_mem_acc_line_nvUFO>>> #%d write %d bytes to %p  val:%p   pc:%p  "
        "line:%d  file: %s\r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  } else {
    DPrintf5(
        "impl_mem_acc_line_nvUFO>>> #%d read %d bytes from %p val:%p   pc:%p "
        "line:%d  file: %s\r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  }

  int tid = thr->tid;
  __MC_STAT

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;

#ifndef BUF_EVENT_ON
  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, _idx, (u64)addr, (u64)pc,
                 (u64)(__sync_fetch_and_add(&uctx->order, 1)), 0, 0);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  return;
#else
  auto &buf = uctx->tlbufs[tid];
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)),
                            (u32)line, (char *)file));
  return;
#endif
}

// skip stack acc
__HOT_CODE
void ns_mem_acc(ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog,
                bool is_write) {
  int tid = thr->tid;
  __MC_STAT
  TLBuffer &buf = uctx->tlbufs[tid];
  s64 ofs = addr - buf.stack_bottom;
  if (0 < ofs && ofs < buf.stack_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped stack\r\n");
    return;
  }
  ofs = addr - buf.tls_bottom;
  if (0 < ofs && ofs < buf.tls_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped tls\r\n");
    return;
  }

  if (is_write) {
    DPrintf5("ns_mem_accUFO>>> #%d write %d bytes to %p  val:%p   pc:%p\r\n",
             thr->tid, (1 << kAccessSizeLog), addr,
             __read_addr(addr, kAccessSizeLog), pc);
  } else {
    DPrintf5("ns_mem_accUFO>>> #%d read %d bytes from %p val:%p   pc:%p\r\n",
             thr->tid, (1 << kAccessSizeLog), addr,
             __read_addr(addr, kAccessSizeLog), pc);
  }

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;
#ifndef BUF_EVENT_ON
  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, (u64)addr, (u64)pc,  (u64)(__sync_fetch_and_add(&uctx->order, 1),0 ,0);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  const int acc_len = 1 << kAccessSizeLog;
  internal_write(fd, addr, acc_len);
#else
  const int acc_len = 1 << kAccessSizeLog;
  if (UNLIKELY(buf.buf_ == nullptr)) {
    buf.open_buf();
    buf.open_file(tid);
  } else if (UNLIKELY(buf.size_ + sizeof(MemAccEvent) + acc_len >=
                      buf.capacity_)) {
    buf.flush();
  }
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)), 0,
                            0));
  Byte *ptr = (Byte *)addr;
  for (int i = 0; i < acc_len; ++i) {
    *(buf.buf_ + buf.size_ + i) = *(ptr + i);
  }
  buf.size_ += acc_len;
#endif
}

__HOT_CODE
void ns_mem_acc_line(ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog,
                     bool is_write, u32 line, char *file) {
  int tid = thr->tid;
  __MC_STAT
  TLBuffer &buf = uctx->tlbufs[tid];
  s64 ofs = addr - buf.stack_bottom;
  if (0 < ofs && ofs < buf.stack_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped stack\r\n");
    return;
  }
  ofs = addr - buf.tls_bottom;
  if (0 < ofs && ofs < buf.tls_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped tls\r\n");
    return;
  }

  if (is_write) {
    DPrintf5(
        "ns_mem_acc_lineUFO>>> #%d write %d bytes to %p  val:%p   pc:%p  "
        "line:%d file:%s \r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  } else {
    DPrintf5(
        "ns_mem_acc_lineUFO>>> #%d read %d bytes from %p val:%p   pc:%p "
        "line:%d file:%s \r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  }

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;

#ifndef BUF_EVENT_ON
  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, (u64)addr, (u64)pc,  (u64)(__sync_fetch_and_add(&uctx->order, 1), 0, 0);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  const int acc_len = 1 << kAccessSizeLog;
  internal_write(fd, addr, acc_len);
#else

  const int acc_len = 1 << kAccessSizeLog;
  if (UNLIKELY(buf.buf_ == nullptr)) {
    buf.open_buf();
    buf.open_file(tid);
  } else if (UNLIKELY(buf.size_ + sizeof(MemAccEvent) + acc_len >=
                      buf.capacity_)) {
    buf.flush();
  }
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)),
                            (u32)line, (char *)file));
  Byte *ptr = (Byte *)addr;
  for (int i = 0; i < acc_len; ++i) {
    *(buf.buf_ + buf.size_ + i) = *(ptr + i);
  }
  buf.size_ += acc_len;
#endif
}

// skip stack acc, no value
__HOT_CODE
void ns_mem_acc_nv(ThreadState *thr, uptr pc, uptr addr, int kAccessSizeLog,
                   bool is_write) {
  int tid = thr->tid;
  __MC_STAT
  TLBuffer &buf = uctx->tlbufs[tid];
  s64 ofs = addr - buf.stack_bottom;
  if (0 < ofs && ofs < buf.stack_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped stack\r\n");
    return;
  }
  ofs = addr - buf.tls_bottom;
  if (0 < ofs && ofs < buf.tls_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped tls\r\n");
    return;
  }

  if (is_write) {
    DPrintf5("ns_mem_acc_nvUFO>>> #%d write %d bytes to %p  val:%p   pc:%p\r\n",
             thr->tid, (1 << kAccessSizeLog), addr,
             __read_addr(addr, kAccessSizeLog), pc);
  } else {
    DPrintf5("ns_mem_acc_nvUFO>>> #%d read %d bytes from %p val:%p   pc:%p\r\n",
             thr->tid, (1 << kAccessSizeLog), addr,
             __read_addr(addr, kAccessSizeLog), pc);
  }

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;

#ifndef BUF_EVENT_ON
  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, _idx, (u64)addr, (u64)pc,
                 (u64)(__sync_fetch_and_add(&uctx->order, 1)), 0, 0);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  return;
#else
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)), 0,
                            0));
#endif
}

__HOT_CODE
void ns_mem_acc_nv_line(ThreadState *thr, uptr pc, uptr addr,
                        int kAccessSizeLog, bool is_write, u32 line,
                        char *file) {
  int tid = thr->tid;
  __MC_STAT
  TLBuffer &buf = uctx->tlbufs[tid];
  s64 ofs = addr - buf.stack_bottom;
  if (0 < ofs && ofs < buf.stack_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped stack\r\n");
    return;
  }
  ofs = addr - buf.tls_bottom;
  if (0 < ofs && ofs < buf.tls_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped tls\r\n");
    return;
  }

  if (is_write) {
    DPrintf5(
        "ns_mem_acc_nv_lineUFO>>> #%d write %d bytes to %p  val:%p   pc:%p  "
        "line:%d   file:%s\r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  } else {
    DPrintf5(
        "ns_mem_acc_nv_lineUFO>>> #%d read %d bytes from %p val:%p   pc:%p\r\n",
        thr->tid, (1 << kAccessSizeLog), addr,
        __read_addr(addr, kAccessSizeLog), pc, line, file);
  }

  u8 type_idx = EventType::MemRead;
  if (is_write) {
    type_idx = EventType::MemWrite;
  }

  u8 sz = static_cast<u8>(kAccessSizeLog);
  type_idx |= sz << 6;

#ifndef BUF_EVENT_ON
  int fd = uctx->tlbufs[tid].trace_fd_;
  MemAccEvent _e(type_idx, _idx, (u64)addr, (u64)pc,
                 (u64)(__sync_fetch_and_add(&uctx->order, 1)), (u32)line,
                 (char *)file);
  internal_write(fd, &_e, sizeof(MemAccEvent));
  return;
#else
  buf.put_event(MemAccEvent(type_idx, (u64)addr, (u64)pc,
                            (u64)(__sync_fetch_and_add(&uctx->order, 1)),
                            (u32)line, (char *)file));
#endif
}

__HOT_CODE
void impl_mem_range_acc(__tsan::ThreadState *thr, uptr pc, uptr addr, uptr size,
                        bool is_write) {
  if (is_write) {
    DPrintf3(
        "impl_mem_range_accUFO>>> #%d range write mem to %p    len %d    "
        "pc:%p\r\n",
        thr->tid, addr, size, pc);
  } else {
    DPrintf3(
        "impl_mem_range_accUFO>>> #%d range read mem from %p    len %d    "
        "pc:%p\r\n",
        thr->tid, addr, size, pc);
  }

  int tid = thr->tid;
#ifdef STAT_ON
  if (is_write) {
    uctx->stat[tid].c_range_w++;
    MC_STAT(thr, c_range_w)
  } else {
    uctx->stat[tid].c_range_r++;
  }
#endif

  u8 type_idx = EventType::MemRangeRead;

  if (is_write) {
    type_idx = EventType::MemRangeWrite;
  }
  uctx->tlbufs[tid].put_event(
      MemRangeAccEvent(type_idx, (u64)addr, (u64)pc, (u32)size,
                       (u64)(__sync_fetch_and_add(&uctx->order, 1))));
}

// no stack
__HOT_CODE
void ns_mem_range_acc(__tsan::ThreadState *thr, uptr pc, uptr addr, uptr size,
                      bool is_write) {
  int tid = thr->tid;
#ifdef STAT_ON
  if (is_write) {
    uctx->stat[tid].c_range_w++;
    MC_STAT(thr, c_range_w)
  } else {
    uctx->stat[tid].c_range_r++;
  }
#endif

  TLBuffer &buf = uctx->tlbufs[tid];
  s64 ofs = addr - buf.stack_bottom;
  if (0 < ofs && ofs < buf.stack_height) {
    uctx->stat[tid].cs_acc++;
    DPrintf3(" skipped stack\r\n");
    return;
  }
  ofs = addr - buf.tls_bottom;
  if (0 < ofs && ofs < buf.tls_height) {
    uctx->stat[tid].cs_range_acc++;
    DPrintf3(" skipped tls\r\n");
    return;
  }

  if (is_write) {
    DPrintf5(
        "ns_mem_range_accUFO>>> #%d range write mem to %p    len %d    "
        "pc:%p\r\n",
        thr->tid, addr, size, pc);
  } else {
    DPrintf5(
        "ns_mem_range_accUFO>>> #%d range read mem from %p    len %d    "
        "pc:%p\r\n",
        thr->tid, addr, size, pc);
  }

  u8 type_idx = EventType::MemRangeRead;
  if (is_write) {
    type_idx = EventType::MemRangeWrite;
  }
  buf.put_event(MemRangeAccEvent(type_idx, (u64)addr, (u64)pc, (u32)size,
                                 (u64)(__sync_fetch_and_add(&uctx->order, 1))));
}
