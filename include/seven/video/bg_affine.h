/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BG_AFFINE_H
#define _LIBSEVEN_VIDEO_BG_AFFINE_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_BG2PA       REG16(0x04000020)
#define REG_BG2PB       REG16(0x04000022)
#define REG_BG2PC       REG16(0x04000024)
#define REG_BG2PD       REG16(0x04000026)

#define REG_BG2X        REG32(0x04000028)
#define REG_BG2Y        REG32(0x0400002C)

#define REG_BG3PA       REG16(0x04000030)
#define REG_BG3PB       REG16(0x04000032)
#define REG_BG3PC       REG16(0x04000034)
#define REG_BG3PD       REG16(0x04000036)

#define REG_BG3X        REG32(0x04000038)
#define REG_BG3Y        REG32(0x0400003C)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BG_AFFINE_H */
