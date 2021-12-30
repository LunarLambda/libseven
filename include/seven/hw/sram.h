#ifndef _LIBSEVEN_HW_SRAM_H
#define _LIBSEVEN_HW_SRAM_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void sramRead(void *dst, u32 len);

extern void sramReadAt(void *dst, u32 len, u32 off);

extern void sramWrite(const void *src, u32 len);

extern void sramWriteAt(const void *src, u32 len, u32 off);

extern u32 sramCompare(const void *src, u32 len);

extern u32 sramCompareAt(const void *src, u32 len, u32 off);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_SRAM_H */
