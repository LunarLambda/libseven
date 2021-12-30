#ifndef _LIBSEVEN_HW_SRAM_H
#define _LIBSEVEN_HW_SRAM_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void sramRead(void *dst, size_t len);

extern void sramReadAt(void *dst, size_t len, size_t off);

extern void sramWrite(const void *src, size_t len);

extern void sramWriteAt(const void *src, size_t len, size_t off);

extern size_t sramCompare(const void *src, size_t len);

extern size_t sramCompareAt(const void *src, size_t len, size_t off);

extern void sramClear(size_t len);

extern void sramClearAt(size_t len, size_t off);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_SRAM_H */
