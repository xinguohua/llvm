

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <cerrno>
#include "defs.h"
#include "reorder.h"
#include "tlbuffer.h"

#include "snappy/snappy.h"


namespace aser {
namespace ufo {


TLBuffer *G_BUF_BASE;

// defined in ufo_rtl.cc
extern ReorderContext *uctx;

void ___w(int fd, Byte* data, u64 len) {
  u64 ret = (u64)__sanitizer::internal_write(fd, data, len);
  if (ret != len) {

  }

}
// thread safe, COMPRESS_ON
void write_file(int fd, Byte* data, u64 len) {
    
    if(fd<0) return;//JEFF

    
  if (uctx->use_compression) {

    struct snappy_env env;
    snappy_init_env(&env);

    size_t outlen = snappy_max_compressed_length(len);
    char *out = (char *) __tsan::internal_alloc(__tsan::MBlockScopedBuf, outlen);
    int err = snappy_compress(&env, (char *) data, len, out, &outlen);
//    DPrintf("SNAPPY>>>#%d err:%d   %llu  ->  %llu\r\n", __tsan::cur_thread()->tid, err, len, outlen);
    snappy_free_env(&env);
    if (err != 0) {
      Printf("!!! #%d Error(%d) compress buffer, len:%d\r\n", __tsan::cur_thread()->tid, err, len);
      internal_free(out);
      Die();
    }
    u32 block_len = outlen;
    internal_write(fd, &block_len, 4);
    internal_write(fd, out, outlen);
    internal_free(out);
  } else {
    internal_write(fd, data, len);
  }

#ifdef SYNC_AT_FLUSH
  fsync(fd);
#endif
}

bool TLBuffer::is_file_open() const {
  return trace_fd_ != -1 && (fcntl(trace_fd_, F_GETFL) >= 0 || errno != EBADF);
}

void TLBuffer::init() {
  buf_ = nullptr;
  size_ = 0;
  capacity_ = 0,
  trace_fd_ = -1,
  e_counter_ = 0;

  tls_height = -1;
  tls_bottom = -1;// lower address
  stack_height = -1;
  stack_bottom = -1;// lower address
}

void TLBuffer::open_buf() {
  u32 sz = uctx->get_buf_size();
  buf_ = (Byte *) internal_alloc(__tsan::MBlockScopedBuf, sz);
  capacity_ = sz;
  size_ = 0;
}

/**
 * if file already exists, append. this is because the tid will be reused.
 *
 */
void TLBuffer::open_file(int tid) {
 //ss
  if (uctx->no_stack) {
    uptr stk_size;
    uptr tls_size;
    __sanitizer::GetThreadStackAndTls(tid == 0, (uptr *) &this->stack_bottom, &stk_size, (uptr *) &this->tls_bottom,
                                      &tls_size);
    this->stack_height = (u32) stk_size;
    this->tls_height = (u32) stk_size;
    DPrintf("UFO>>> #%d  stack:%llu %u   tls:%llu %u\r\n",
           __tsan::cur_thread()->tid, this->stack_bottom, this->stack_height, tls_bottom, this->tls_height);
  }
    
  uptr pre_len = __sanitizer::internal_strlen(uctx->trace_dir);
  const uptr name_len = pre_len + 5;
  char *file_name = (char *) internal_alloc(__tsan::MBlockScopedBuf, name_len);
    
    __sanitizer::internal_snprintf(file_name, name_len, "%s/%d", uctx->trace_dir, tid);

  trace_fd_ = __sanitizer::internal_open(file_name, O_CREAT | O_APPEND | O_WRONLY, 0666);
  if (trace_fd_ < 0) {

          fprintf(stderr, "UFO>>>#%d could not open file '%s' code %d\n", tid, file_name, trace_fd_);
          perror("");
  }
    
        
  internal_free(file_name);
  u32 data = uctx->use_compression;
  UFOHeader header(tid, uctx->time_started, data);
  internal_write(trace_fd_, &header, sizeof(UFOHeader));

  DPrintf("UFO>>>#%d this %p fname:[%s] fd:%d    %s %d \r\n",
          tid, this, file_name, trace_fd_, __PRETTY_FUNCTION__, __LINE__);

}

void TLBuffer::flush() {
    
    //JEFF: TODO
    //TEST asynchronous logging
    int tid = this - G_BUF_BASE;
    
  if (UNLIKELY( ! is_file_open())) {
//    int tid = this - G_BUF_BASE;
    open_file(tid);
  }

    //JEFF: do nothing if file not opened
    if(trace_fd_<0) return;
    
  if (uctx->use_io_q) {
    uctx->out_queue->push(this);
  } else {
    write_file(trace_fd_, buf_, size_);
  }
  size_ = 0;
}

void TLBuffer::finish() {
  if (buf_ != nullptr) {
    if (size_ > 0) {
      if (UNLIKELY( ! is_file_open())) {
        int tid = this - G_BUF_BASE;
        open_file(tid);
      }
        
//        //JEFF: do nothing if file not opened
        if(trace_fd_<0) return;
        
      write_file(trace_fd_, buf_, size_);
      size_ = 0;
    }
    internal_free(buf_);
    buf_ = nullptr;
  }
  capacity_ = 0;

  if (is_file_open()) {
//      trace_fd_ valid
    fsync(trace_fd_);
    __sanitizer::internal_close(trace_fd_);
  }
}

void TLBuffer::reset() {
  size_ = 0;
  trace_fd_ = -1;
  e_counter_ = 0;
}


} // ns ufo_bench
} // ns bw

