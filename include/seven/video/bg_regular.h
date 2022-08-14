/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_BG_REGULAR_H
#define _LIBSEVEN_VIDEO_BG_REGULAR_H

#include <seven/base.h>
#include <seven/hw/video.h>
#include <seven/video/bg_scroll.h>
#include <seven/video/bg_tiled.h>

_LIBSEVEN_EXTERN_C

#define BF_TILE_NUMBER_OFFSET 0
#define BF_TILE_NUMBER_LENGTH 10

#define TILE_NUMBER(n) BITFIELD(TILE_NUMBER, (n))

#define BF_TILE_PALETTE_OFFSET 12
#define BF_TILE_PALETTE_LENGTH 4

#define TILE_PALETTE(n) BITFIELD(TILE_PALETTE, (n))

enum Tile
{
    TILE_FLIP_H = BIT(10),
    TILE_FLIP_V = BIT(11),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_BG_REGULAR_H */
