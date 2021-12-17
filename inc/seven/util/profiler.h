#ifndef _LIBSEVEN_UTIL_PROFILER_H
#define _LIBSEVEN_UTIL_PROFILER_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern u32 profileFunction(u32 (*function)(void), u32 *return_value);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_UTIL_PROFILER_H */
