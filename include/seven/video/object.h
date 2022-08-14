/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_VIDEO_OBJECT_H
#define _LIBSEVEN_VIDEO_OBJECT_H

#include <seven/base.h>
#include <seven/hw/video.h>

_LIBSEVEN_EXTERN_C

struct Object
{
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 prio;
} ALIGN(4);

#define BF_ATTR0_Y_OFFSET 0
#define BF_ATTR0_Y_LENGTH 8

#define ATTR0_Y(n) BITFIELD(ATTR0_Y, (n))

#define BF_ATTR0_MODE_OFFSET 8
#define BF_ATTR0_MODE_LENGTH 2

#define ATTR0_MODE(n) BITFIELD(ATTR0_MODE, (n))

#define BF_ATTR0_GFX_OFFSET 10
#define BF_ATTR0_GFX_LENGTH 2

#define ATTR0_GFX(n) BITFIELD(ATTR0_GFX, (n))

#define BF_ATTR0_SHAPE_OFFSET 14
#define BF_ATTR0_SHAPE_LENGTH 2

#define ATTR0_SHAPE(n) BITFIELD(ATTR0_SHAPE, (n))

enum Attribute0
{
    ATTR0_MODE_REGULAR          = ATTR0_MODE(0),
    ATTR0_MODE_AFFINE           = ATTR0_MODE(1),
    ATTR0_MODE_HIDE             = ATTR0_MODE(2),
    ATTR0_MODE_AFFINE_DOUBLE    = ATTR0_MODE(3),

    ATTR0_GFX_REGULAR           = ATTR0_GFX(0),
    ATTR0_GFX_BLEND             = ATTR0_GFX(1),
    ATTR0_GFX_WINDOW            = ATTR0_GFX(2),

    ATTR0_MOSAIC_ENABLE         = BIT(12),

    ATTR0_4BPP                  = BIT(13),
    ATTR0_8BPP                  = !ATTR0_4BPP,

    ATTR0_SQUARE                = ATTR0_SHAPE(0),
    ATTR0_HORIZONTAL            = ATTR0_SHAPE(1),
    ATTR0_VERTICAL              = ATTR0_SHAPE(2),
};

#define BF_ATTR1_X_OFFSET 0
#define BF_ATTR1_X_LENGTH 9

#define ATTR1_X(n) BITFIELD(ATTR1_X, (n))

#define BF_ATTR1_AFFINE_ID_OFFSET 9
#define BF_ATTR1_AFFINE_ID_LENGTH 5

#define ATTR1_AFFINE_ID(n) BITFIELD(ATTR1_AFFINE_ID, (n))

#define BF_ATTR1_SIZE_OFFSET 14
#define BF_ATTR1_SIZE_LENGTH 2

#define ATTR1_SIZE(n) BITFIELD(ATTR1_SIZE, (n))

enum Attribute1
{
    ATTR1_HORIZONTAL_FLIP   = BIT(12),
    ATTR1_VERTICAL_FLIP     = BIT(13),

    // Square
    ATTR1_SIZE_8x8          = ATTR1_SIZE(0),
    ATTR1_SIZE_16x16        = ATTR1_SIZE(1),
    ATTR1_SIZE_32x32        = ATTR1_SIZE(2),
    ATTR1_SIZE_64x64        = ATTR1_SIZE(3),

    // Hortizontal
    ATTR1_SIZE_16x8         = ATTR1_SIZE(0),
    ATTR1_SIZE_32x8         = ATTR1_SIZE(1),
    ATTR1_SIZE_32x16        = ATTR1_SIZE(2),
    ATTR1_SIZE_64x32        = ATTR1_SIZE(3),

    // Vertical
    ATTR1_SIZE_8x16         = ATTR1_SIZE(0),
    ATTR1_SIZE_8x32         = ATTR1_SIZE(1),
    ATTR1_SIZE_16x32        = ATTR1_SIZE(2),
    ATTR1_SIZE_32x64        = ATTR1_SIZE(3),
};

#define BF_ATTR2_TILE_ID_OFFSET 0
#define BF_ATTR2_TILE_ID_LENGTH 9

#define ATTR2_TILE_ID(n) BITFIELD(ATTR2_TILE_ID, (n))

#define BF_ATTR2_PRIORITY_OFFSET 10
#define BF_ATTR2_PRIORITY_LENGTH 2

#define ATTR2_PRIORITY(n) BITFIELD(ATTR2_PRIORITY, (n))

#define BF_ATTR2_PALETTE_BANK_OFFSET 12
#define BF_ATTR2_PALETTE_BANK_LENGTH 4

#define ATTR2_PALETTE_BANK(n) BITFIELD(ATTR2_PALETTE_BANK, (n))

enum Attribute2
{
    ATTR2_PRIORITY_MIN = ATTR2_PRIORITY(3),
    ATTR2_PRIORITY_MAX = ATTR2_PRIORITY(0),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_OBJECT_H */
