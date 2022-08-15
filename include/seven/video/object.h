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

#define BF_OBJ_Y_OFFSET 0
#define BF_OBJ_Y_LENGTH 8

#define OBJ_Y(n) BITFIELD(OBJ_Y, (n))

#define BF_OBJ_MODE_OFFSET 8
#define BF_OBJ_MODE_LENGTH 2

#define OBJ_MODE(n) BITFIELD(OBJ_MODE, (n))

#define BF_OBJ_GFX_OFFSET 10
#define BF_OBJ_GFX_LENGTH 2

#define OBJ_GFX(n) BITFIELD(OBJ_GFX, (n))

#define BF_OBJ_SHAPE_OFFSET 14
#define BF_OBJ_SHAPE_LENGTH 2

#define OBJ_SHAPE(n) BITFIELD(OBJ_SHAPE, (n))

enum ObjectAttribute0
{
    OBJ_MODE_REGULAR          = OBJ_MODE(0),
    OBJ_MODE_AFFINE           = OBJ_MODE(1),
    OBJ_MODE_HIDE             = OBJ_MODE(2),
    OBJ_MODE_AFFINE_DOUBLE    = OBJ_MODE(3),

    OBJ_GFX_REGULAR           = OBJ_GFX(0),
    OBJ_GFX_BLEND             = OBJ_GFX(1),
    OBJ_GFX_WINDOW            = OBJ_GFX(2),

    OBJ_MOSAIC_ENABLE         = BIT(12),

    OBJ_4BPP                  = BIT(13),
    OBJ_8BPP                  = !OBJ_4BPP,

    OBJ_SQUARE                = OBJ_SHAPE(0),
    OBJ_HORIZONTAL            = OBJ_SHAPE(1),
    OBJ_VERTICAL              = OBJ_SHAPE(2),
};

#define BF_OBJ_X_OFFSET 0
#define BF_OBJ_X_LENGTH 9

#define OBJ_X(n) BITFIELD(OBJ_X, (n))

#define BF_OBJ_AFFINE_ID_OFFSET 9
#define BF_OBJ_AFFINE_ID_LENGTH 5

#define OBJ_AFFINE_ID(n) BITFIELD(OBJ_AFFINE_ID, (n))

#define BF_OBJ_SIZE_OFFSET 14
#define BF_OBJ_SIZE_LENGTH 2

#define OBJ_SIZE(n) BITFIELD(OBJ_SIZE, (n))

enum ObjectAttribute1
{
    OBJ_HORIZONTAL_FLIP   = BIT(12),
    OBJ_VERTICAL_FLIP     = BIT(13),

    // Square
    OBJ_SIZE_8x8          = OBJ_SIZE(0),
    OBJ_SIZE_16x16        = OBJ_SIZE(1),
    OBJ_SIZE_32x32        = OBJ_SIZE(2),
    OBJ_SIZE_64x64        = OBJ_SIZE(3),

    // Hortizontal
    OBJ_SIZE_16x8         = OBJ_SIZE(0),
    OBJ_SIZE_32x8         = OBJ_SIZE(1),
    OBJ_SIZE_32x16        = OBJ_SIZE(2),
    OBJ_SIZE_64x32        = OBJ_SIZE(3),

    // Vertical
    OBJ_SIZE_8x16         = OBJ_SIZE(0),
    OBJ_SIZE_8x32         = OBJ_SIZE(1),
    OBJ_SIZE_16x32        = OBJ_SIZE(2),
    OBJ_SIZE_32x64        = OBJ_SIZE(3),
};

#define BF_OBJ_TILE_ID_OFFSET 0
#define BF_OBJ_TILE_ID_LENGTH 9

#define OBJ_TILE_ID(n) BITFIELD(OBJ_TILE_ID, (n))

#define BF_OBJ_PRIORITY_OFFSET 10
#define BF_OBJ_PRIORITY_LENGTH 2

#define OBJ_PRIORITY(n) BITFIELD(OBJ_PRIORITY, (n))

#define BF_OBJ_PALETTE_ID_OFFSET 12
#define BF_OBJ_PALETTE_ID_LENGTH 4

#define OBJ_PALETTE_ID(n) BITFIELD(OBJ_PALETTE_ID, (n))

enum ObjectAttribute2
{
    OBJ_PRIORITY_MIN = OBJ_PRIORITY(3),
    OBJ_PRIORITY_MAX = OBJ_PRIORITY(0),
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_OBJECT_H */
