/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BG_AFFINE_H
#define _LIBSEVEN_VIDEO_BG_AFFINE_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_BG2PA       VOLADDR(0x04000020, u16)
#define REG_BG2PB       VOLADDR(0x04000022, u16)
#define REG_BG2PC       VOLADDR(0x04000024, u16)
#define REG_BG2PD       VOLADDR(0x04000026, u16)

#define REG_BG2X        VOLADDR(0x04000028, u32)
#define REG_BG2Y        VOLADDR(0x0400002C, u32)

#define REG_BG3PA       VOLADDR(0x04000030, u16)
#define REG_BG3PB       VOLADDR(0x04000032, u16)
#define REG_BG3PC       VOLADDR(0x04000034, u16)
#define REG_BG3PD       VOLADDR(0x04000036, u16)

#define REG_BG3X        VOLADDR(0x04000038, u32)
#define REG_BG3Y        VOLADDR(0x0400003C, u32)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BG_AFFINE_H */
