/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BLEND_H
#define _LIBSEVEN_VIDEO_BLEND_H

#include <seven/base.h>
#include <seven/hw/video.h>

_LIBSEVEN_EXTERN_C

#define REG_BLDCNT      VOLADDR(0x04000050, u16)
#define REG_BLDALPHA    VOLADDR(0x04000052, u16)
#define REG_BLDVAL      VOLADDR(0x04000054, u16)

#define BF_BLEND_MODE_OFFSET 6
#define BF_BLEND_MODE_LENGTH 2

#define BLEND_MODE(n) BITFIELD(BLEND_MODE, (n))

enum BlendControl
{
    BLEND_TARGET_BG0      = BIT(0),
    BLEND_TARGET_BG1      = BIT(1),
    BLEND_TARGET_BG2      = BIT(2),
    BLEND_TARGET_BG3      = BIT(3),
    BLEND_TARGET_OBJ      = BIT(4),
    BLEND_TARGET_BD       = BIT(5),

    BLEND_MODE_NONE       = BLEND_MODE(0),
    BLEND_MODE_ALPHA      = BLEND_MODE(1),
    BLEND_MODE_WHITE      = BLEND_MODE(2),
    BLEND_MODE_BLACK      = BLEND_MODE(3),

    // Only used with BLEND_MODE_ALPHA
    BLEND_TARGET2_BG0     = BIT(8),
    BLEND_TARGET2_BG1     = BIT(9),
    BLEND_TARGET2_BG2     = BIT(10),
    BLEND_TARGET2_BG3     = BIT(11),
    BLEND_TARGET2_OBJ     = BIT(12),
    BLEND_TARGET2_BD      = BIT(13),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BLEND_H */
