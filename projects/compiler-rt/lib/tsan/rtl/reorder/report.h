// report stack tracing in Sanitizer style

#ifndef UFO_REPORT_H
#define UFO_REPORT_H

#include "defs.h"
#include "reorder_record.h"
#include "reorder.h"


//#define DPrintf Printf

namespace aser {
namespace ufo {

extern ReorderContext *uctx;


void print_callstack(__tsan::ThreadState *thr, uptr pc);


}
}


#endif //UFO_REPORT_H
