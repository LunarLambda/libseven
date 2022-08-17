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

enum ObjectAttribute0
{
#define BF_OBJ_Y_POS_OFFSET 0
#define BF_OBJ_Y_POS_LENGTH 8

#define BF_OBJ_MODE_OFFSET 8
#define BF_OBJ_MODE_LENGTH 2

    OBJ_MODE_REGULAR = OBJ_MODE(0),
    OBJ_MODE_AFFINE  = OBJ_MODE(1),
    OBJ_MODE_HIDDEN  = OBJ_MODE(2),
    OBJ_MODE_DOUBLE  = OBJ_MODE(3),

#define BF_OBJ_TYPE_OFFSET 10
#define BF_OBJ_TYPE_LENGTH 2

    OBJ_TYPE_REGULAR = OBJ_TYPE(0),
    OBJ_TYPE_BLEND   = OBJ_TYPE(1),
    OBJ_TYPE_WINDOW  = OBJ_TYPE(2),

    OBJ_MOSAIC_ENABLE = BIT(12),

    OBJ_TILE_8BPP = BIT(13),
    OBJ_TILE_4BPP = !OBJ_TILE_8BPP,

#define BF_OBJ_SHAPE_OFFSET 14
#define BF_OBJ_SHAPE_LENGTH 2

    OBJ_SHAPE_SQUARE = OBJ_SHAPE(0),
    OBJ_SHAPE_WIDE = OBJ_SHAPE(1),
    OBJ_SHAPE_TALL = OBJ_SHAPE(2),
};

enum ObjectAttribute1
{
#define BF_OBJ_X_POS_OFFSET 0
#define BF_OBJ_X_POS_LENGTH 9

#define BF_OBJ_AFFINE_MATRIX_OFFSET 9
#define BF_OBJ_AFFINE_MATRIX_LENGTH 5

    OBJ_FLIP_H = BIT(12),
    OBJ_FLIP_V = BIT(13),

#define BF_OBJ_SIZE_OFFSET 14
#define BF_OBJ_SIZE_LENGTH 2

    // Square
    OBJ_SIZE_8X8 = OBJ_SIZE(0),
    OBJ_SIZE_16X16 = OBJ_SIZE(1),
    OBJ_SIZE_32X32 = OBJ_SIZE(2),
    OBJ_SIZE_64X64 = OBJ_SIZE(3),

    // Wide
    OBJ_SIZE_16X8 = OBJ_SIZE(0),
    OBJ_SIZE_32X8 = OBJ_SIZE(1),
    OBJ_SIZE_32X16 = OBJ_SIZE(2),
    OBJ_SIZE_64X32 = OBJ_SIZE(3),

    // Tall
    OBJ_SIZE_8X16 = OBJ_SIZE(0),
    OBJ_SIZE_8X32 = OBJ_SIZE(1),
    OBJ_SIZE_16X32 = OBJ_SIZE(2),
    OBJ_SIZE_32X64 = OBJ_SIZE(3),
};

enum ObjectAttribute2
{
#define BF_OBJ_TILE_NUMBER_OFFSET 0
#define BF_OBJ_TILE_NUMBER_LENGHT 10

#define BF_OBJ_PRIORITY_OFFSET 10
#define BF_OBJ_PRIORITY_LENGTH 2

    OBJ_PRIORITY_MIN = OBJ_PRIORITY(3),
    OBJ_PROIRITY_MAX = OBJ_PRIORITY(0),

#define BF_OBJ_PALETTE_OFFSET 12
#define BF_OBJ_PALETTE_LENGHT 4
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_VIDEO_OBJECT_H */
