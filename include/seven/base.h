#ifndef _LIBSEVEN_BASE_H
#define _LIBSEVEN_BASE_H

#ifdef __cplusplus
#define _LIBSEVEN_EXTERN_C extern "C" {
#define _LIBSEVEN_EXTERN_C_END }
#else
#define _LIBSEVEN_EXTERN_C
#define _LIBSEVEN_EXTERN_C_END
#endif

_LIBSEVEN_EXTERN_C

#include <seven/base/attributes.h>
#include <seven/base/bits.h>
#include <seven/base/registers.h>
#include <seven/base/types.h>

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_BASE_H */
