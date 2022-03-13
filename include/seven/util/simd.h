/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_UTIL_SIMD_H
#define _LIBSEVEN_UTIL_SIMD_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

enum SIMDMask
{
    SIMD_MASK_4X8   = 0x80808080, // 4 Bytes packed
    SIMD_MASK_2X16  = 0x80008000, // 2 Halfwords packed
    SIMD_MASK_2XRGB = 0xC210C210, // 2 RGB5 colors packed
};

extern void simdAdd(u32 mask, void *lhs, const void *rhs, usize len);
extern void simdSub(u32 mask, void *lhs, const void *rhs, usize len);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_UTIL_SIMD_H */
