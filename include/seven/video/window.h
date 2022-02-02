/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_WINDOW_H
#define _LIBSEVEN_VIDEO_WINDOW_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define REG_WIN0H       REG16(0x04000040)
#define REG_WIN1H       REG16(0x04000042)
#define REG_WIN0V       REG16(0x04000044)
#define REG_WIN1V       REG16(0x04000046)

#define REG_WIN0IN      REG8(0x04000048)
#define REG_WIN1IN      REG8(0x04000049)
#define REG_WIN0OUT     REG8(0x0400004A)
#define REG_WIN1OUT     REG8(0x0400004B)

enum WindowControl
{
    WINDOW_BG0_ENABLE   = BIT(0),
    WINDOW_BG1_ENABLE   = BIT(1),
    WINDOW_BG2_ENABLE   = BIT(2),
    WINDOW_BG3_ENABLE   = BIT(3),
    WINDOW_OBJ_ENABLE   = BIT(4),
    WINDOW_BLEND_ENABLE = BIT(5),
};

#define WINDOW_DIM(l, h)        ((((l) & 255) << 8) | ((h) & 255))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_WINDOW_H */
