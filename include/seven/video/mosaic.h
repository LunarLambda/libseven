/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_MOSAIC_H
#define _LIBSEVEN_VIDEO_MOSAIC_H

#include <seven/base.h>
#include <seven/hw/video.h>

_LIBSEVEN_EXTERN_C

#define REG_MOSAIC VOLADDR(0x0400004C, u16)

#define BF_MOSAIC_BG_H_OFFSET  0
#define BF_MOSAIC_BG_H_LENGTH  4

#define MOSAIC_BG_H(v) BITFIELD(MOSAIC_BG_H, (v))

#define BF_MOSAIC_BG_V_OFFSET  4
#define BF_MOSAIC_BG_V_LENGTH  4

#define MOSAIC_BG_V(v) BITFIELD(MOSAIC_BG_V, (v))

#define BF_MOSAIC_OBJ_H_OFFSET 8
#define BF_MOSAIC_OBJ_H_LENGTH 4

#define MOSAIC_OBJ_H(v) BITFIELD(MOSAIC_OBJ_H, (v))

#define BF_MOSAIC_OBJ_V_OFFSET 12
#define BF_MOSAIC_OBJ_V_LENGTH 4

#define MOSAIC_OBJ_V(v) BITFIELD(MOSAIC_OBJ_V, (v))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_MOSAIC_H */
