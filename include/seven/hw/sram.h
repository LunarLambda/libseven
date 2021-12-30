#ifndef _LIBSEVEN_HW_SRAM_H
#define _LIBSEVEN_HW_SRAM_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void sramRead(u8 *dst, u32 len);

extern void sramReadAt(u8 *dst, u32 len, u32 off);

extern void sramWrite(const u8 *src, u32 len);

extern void sramWriteAt(const u8 *src, u32 len, u32 off);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_SRAM_H */
