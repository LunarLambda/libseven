/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_BASE_TYPES_H
#define _LIBSEVEN_BASE_TYPES_H

#include <seven/base.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

_LIBSEVEN_EXTERN_C

typedef int8_t          i8;
typedef int16_t         i16;
typedef int32_t         i32;
typedef int64_t         i64;
typedef ptrdiff_t       isize;
typedef intptr_t        iptr;

typedef int8_t          s8;
typedef int16_t         s16;
typedef int32_t         s32;
typedef int64_t         s64;
typedef ptrdiff_t       ssize;
typedef intptr_t        sptr;

typedef uint8_t         u8;
typedef uint16_t        u16;
typedef uint32_t        u32;
typedef uint64_t        u64;
typedef size_t          usize;
typedef uintptr_t       uptr;

#define I8_MIN          INT8_MIN
#define I16_MIN         INT16_MIN
#define I32_MIN         INT32_MIN
#define I64_MIN         INT64_MIN
#define ISIZE_MIN       PTRDIFF_MIN
#define IPTR_MIN        INTPTR_MIN

#define I8_MAX          INT8_MAX
#define I16_MAX         INT16_MAX
#define I32_MAX         INT32_MAX
#define I64_MAX         INT64_MAX
#define ISIZE_MAX       PTRDIFF_MAX
#define IPTR_MAX        INTPTR_MAX

#define I8_BITS         8
#define I16_BITS        16
#define I32_BITS        32
#define I64_BITS        64
#define ISIZE_BITS      (CHAR_BIT * sizeof(isize))
#define IPTR_BITS       (CHAR_BIT * sizeof(iptr))

#define S8_MIN          INT8_MIN
#define S16_MIN         INT16_MIN
#define S32_MIN         INT32_MIN
#define S64_MIN         INT64_MIN
#define SSIZE_MIN       PTRDIFF_MIN
#define SPTR_MIN        INTPTR_MIN

#define S8_MAX          INT8_MAX
#define S16_MAX         INT16_MAX
#define S32_MAX         INT32_MAX
#define S64_MAX         INT64_MAX
#define SSIZE_MAX       PTRDIFF_MAX
#define SPTR_MAX        INTPTR_MAX

#define S8_BITS         8
#define S16_BITS        16
#define S32_BITS        32
#define S64_BITS        64
#define SSIZE_BITS      (CHAR_BIT * sizeof(ssize))
#define SPTR_BITS       (CHAR_BIT * sizeof(sptr))

#define U8_MIN          0
#define U16_MIN         0
#define U32_MIN         0
#define U64_MIN         0
#define USIZE_MIN       0
#define UPTR_MIN        0

#define U8_MAX          UINT8_MAX
#define U16_MAX         UINT16_MAX
#define U32_MAX         UINT32_MAX
#define U64_MAX         UINT64_MAX
#define USIZE_MAX       SIZE_MAX
#define UPTR_MAX        UINTPTR_MAX

#define U8_BITS         8
#define U16_BITS        16
#define U32_BITS        32
#define U64_BITS        64
#define USIZE_BITS      (CHAR_BIT * sizeof(usize))
#define UPTR_BITS       (CHAR_BIT * sizeof(uptr))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_BASE_TYPES_H */
