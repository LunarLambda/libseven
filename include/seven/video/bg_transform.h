/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BG_TRANSFORM_H
#define _LIBSEVEN_VIDEO_BG_TRANSFORM_H

#include <seven/base.h>
#include <seven/hw/video.h>
#include <seven/video/matrix.h>

_LIBSEVEN_EXTERN_C

#define REG_BG2PA       VOLADDR(0x04000020, i16)
#define REG_BG2PB       VOLADDR(0x04000022, i16)
#define REG_BG2PC       VOLADDR(0x04000024, i16)
#define REG_BG2PD       VOLADDR(0x04000026, i16)

#define REG_BG2MAT      VOLADDR(0x04000020, struct Matrix)

#define REG_BG2X        VOLADDR(0x04000028, i32)
#define REG_BG2Y        VOLADDR(0x0400002C, i32)

#define REG_BG3PA       VOLADDR(0x04000030, i16)
#define REG_BG3PB       VOLADDR(0x04000032, i16)
#define REG_BG3PC       VOLADDR(0x04000034, i16)
#define REG_BG3PD       VOLADDR(0x04000036, i16)

#define REG_BG3MAT      VOLADDR(0x04000030, struct Matrix)

#define REG_BG3X        VOLADDR(0x04000038, i32)
#define REG_BG3Y        VOLADDR(0x0400003C, i32)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BG_TRANSFORM_H */
