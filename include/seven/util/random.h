#ifndef _LIBSEVEN_UTIL_RANDOM_H
#define _LIBSEVEN_UTIL_RANDOM_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void randSetSeed(u32 seed);

extern u32 randNext(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_UTIL_RANDOM_H */
