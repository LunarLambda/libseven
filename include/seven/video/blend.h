/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BLEND_H
#define _LIBSEVEN_VIDEO_BLEND_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_BLDCNT      REG16(0x04000050)
// TODO: BLDALPHA defines
#define REG_BLDALPHA    REG16(0x04000052)
#define REG_BLDCOEFF    REG16(0x04000054)

#define BF_BLD_MODE_OFFSET 6
#define BF_BLD_MODE_LENGTH 2

enum BlendControl
{
    BLD_TARGET_BG0      = BIT(0),
    BLD_TARGET_BG1      = BIT(1),
    BLD_TARGET_BG2      = BIT(2),
    BLD_TARGET_BG3      = BIT(3),
    BLD_TARGET_OBJ      = BIT(4),
    BLD_TARGET_BD       = BIT(5),

    BLD_MODE_NONE       = BITFIELD(BLD_MODE, 0),
    BLD_MODE_ALPHA      = BITFIELD(BLD_MODE, 1),
    BLD_MODE_WHITE      = BITFIELD(BLD_MODE, 2),
    BLD_MODE_BLACK      = BITFIELD(BLD_MODE, 3),

    // Only used with BLD_MODE_ALPHA
    BLD_TARGET2_BG0      = BIT(8),
    BLD_TARGET2_BG1      = BIT(9),
    BLD_TARGET2_BG2      = BIT(10),
    BLD_TARGET2_BG3      = BIT(11),
    BLD_TARGET2_OBJ      = BIT(12),
    BLD_TARGET2_BD       = BIT(13),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BLEND_H */
