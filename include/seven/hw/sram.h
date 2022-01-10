/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_SRAM_H
#define _LIBSEVEN_HW_SRAM_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void sramRead(void *dst, usize len);

extern void sramReadAt(void *dst, usize len, usize off);

extern void sramWrite(const void *src, usize len);

extern void sramWriteAt(const void *src, usize len, usize off);

extern usize sramCompare(const void *src, usize len);

extern usize sramCompareAt(const void *src, usize len, usize off);

extern void sramClear(usize len);

extern void sramClearAt(usize len, usize off);

extern void sramRead64(void *dst, size_t len);

extern void sramReadAt64(void *dst, size_t len, size_t off);

extern void sramWrite64(const void *src, size_t len);

extern void sramWriteAt64(const void *src, size_t len, size_t off);

extern void sramClear64(size_t len);

extern void sramClearAt64(size_t len, size_t off);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_SRAM_H */
