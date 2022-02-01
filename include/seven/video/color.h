/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_COLOR_H
#define _LIBSEVEN_VIDEO_COLOR_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define BF_COLOR_R_OFFSET 0
#define BF_COLOR_R_LENGTH 5
#define BF_COLOR_G_OFFSET 5
#define BF_COLOR_G_LENGTH 5
#define BF_COLOR_B_OFFSET 10
#define BF_COLOR_B_LENGTH 5

#define RGB5(r, g, b) \
    ((u16)(BITFIELD(COLOR_R, (r)) | BITFIELD(COLOR_G, (g)) | BITFIELD(COLOR_B, (b))))

#define RGB8(r, g, b) \
    RGB5((r) >> 3, (g) >> 3, (b) >> 3)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_COLOR_H */
