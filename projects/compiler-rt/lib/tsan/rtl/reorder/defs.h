
#ifndef UFO_DEFS_H
#define UFO_DEFS_H

#include "../../../sanitizer_common/sanitizer_internal_defs.h"
#include "../../../sanitizer_common/sanitizer_common.h"
#include "../../../sanitizer_common/sanitizer_atomic.h"
#include "../../../sanitizer_common/sanitizer_posix.h"
#include "../tsan_rtl.h"

// for test only, do not disable it
#define BUF_EVENT_ON

// sync file on flush(), should always on
#define SYNC_AT_FLUSH


// enable statistic
#define STAT_ON


const unsigned long long UFO_VERSION = 20161001;

typedef unsigned char Byte;
typedef unsigned short TidType;

const unsigned int MAX_THREAD = 8192;

#define PACKED_STRUCT(NAME)\
  struct __attribute__ ((__packed__)) NAME

#define __HOT_CODE\
    __attribute__((optimize("unroll-loops")))\
    __attribute__((hot))\


// for benchmark
// do nothing, framework overhead 3X
const char* const ENV_UFO_ON = "UFO_ON";

// assuming no stack variables are shared among threads.
// do not record acc events on stack or static region
const char* const ENV_NO_STACK_ACC = "UFO_NO_STACK";
const int NO_STACK_ACC = 1;//JEFF by default don't trace stack access


const char* const ENV_TL_BUF_SIZE = "UFO_TL_BUF";
const unsigned long DEFAULT_BUF_PRE_THR = 128; // 128 MB

// uaf trace file directory
const char* const ENV_TRACE_DIR = "UFO_TDIR";
const char* const DEFAULT_TRACE_DIR = "ufo_traces";


const char * const ENV_USE_COMPRESS = "UFO_COMPRESS";
const int COMPRESS_ON = 0;//JEFF by default don't compress

const char * const ENV_USE_IO_Q = "UFO_ASYNC_IO";
const int ASYNC_IO_ON = 1;

const char * const ENV_IO_Q_SIZE = "UFO_IO_Q";
const int DEFAULT_IO_Q_SIZE = 4;

const char* const ENV_TRACE_FUNC = "UFO_CALL";


const char * const ENV_NO_VALUE = "UFO_NO_VALUE";

const char* const ENV_PRINT_STAT = "UFO_STAT";

const char* const ENV_PTR_PROP = "UFO_PTR_PROP";

const unsigned int DIR_MAX_LEN = 255;

const char* const NAME_MODULE_INFO = "/_module_info.txt";
const char* const NAME_STAT_FILE = "/_statistics.txt";
const char* const NAME_STAT_CSV = "/_statistics.csv";

/**
 * dev stopped
 * memory threshold:
 * if threshold 1 is exceeded, reduce current tl buffer size by 2;
 * if threshold 2 is exceeded, reduce current tl buffer size by 4.
 */
const char * const ENV_UFO_MEM_T1 = "UFO_MEM_T1";
const char * const ENV_UFO_MEM_T2 = "UFO_MEM_T2";

const unsigned long DEFAULT_MEM_THRESHOLD_1 = 128ul * 80; // 10G
const unsigned long DEFAULT_MEM_THRESHOLD_2 = 128ul * 120; // 15G

const unsigned long MIN_BUF_SZ = 32 * 1024 * 1024;


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

using __sanitizer::atomic_uint8_t;
using __sanitizer::atomic_uint16_t;
using __sanitizer::atomic_uint32_t;
using __sanitizer::atomic_uint64_t;
using __sanitizer::atomic_load_relaxed;
using __sanitizer::atomic_store_relaxed;

//using namespace __tsan;
using __sanitizer::internal_write;
using __tsan::internal_alloc;
using __tsan::internal_free;
using __sanitizer::Die;


#endif //UFO_DEFS_H
