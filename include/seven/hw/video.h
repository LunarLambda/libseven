/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_VIDEO_H
#define _LIBSEVEN_HW_VIDEO_H

#include <seven/base.h>

#define LCD_WIDTH       240
#define LCD_HEIGHT      160

_LIBSEVEN_EXTERN_C

// Display Control

#define REG_DISPCNT             REG16(0x04000000)

#define BF_LCD_MODE_OFFSET 0
#define BF_LCD_MODE_LENGTH 3

enum DisplayControl
{
    LCD_MODE_0                  = BITFIELD(LCD_MODE, 0),
    LCD_MODE_1                  = BITFIELD(LCD_MODE, 1),
    LCD_MODE_2                  = BITFIELD(LCD_MODE, 2),
    LCD_MODE_3                  = BITFIELD(LCD_MODE, 3),
    LCD_MODE_4                  = BITFIELD(LCD_MODE, 4),
    LCD_MODE_5                  = BITFIELD(LCD_MODE, 5),

    LCD_MODE_TILED              = LCD_MODE_0,
    LCD_MODE_MIXED              = LCD_MODE_1,
    LCD_MODE_AFFINE             = LCD_MODE_2,
    LCD_MODE_BITMAP             = LCD_MODE_3,
    LCD_MODE_BITMAP_PALETTED    = LCD_MODE_4,
    LCD_MODE_BITMAP_SMALL       = LCD_MODE_5,

    LCD_FRAME_SELECT            = BIT(4),

    LCD_HBLANK_OAM_ACCESS       = BIT(5),

    LCD_OBJ_MAPPING_1D          = BIT(6),
    LCD_OBJ_MAPPING_2D          = !LCD_OBJ_MAPPING_1D,

    LCD_FORCE_BLANK             = BIT(7),

    LCD_BG0_ENABLE              = BIT(8),
    LCD_BG1_ENABLE              = BIT(9),
    LCD_BG2_ENABLE              = BIT(10),
    LCD_BG3_ENABLE              = BIT(11),
    LCD_OBJ_ENABLE              = BIT(12),
    LCD_WIN0_ENABLE             = BIT(13),
    LCD_WIN1_ENABLE             = BIT(14),
    LCD_OBJ_WINDOW_ENABLE       = BIT(15),
};


// Display Status

#define REG_DISPSTAT    REG16(0x04000004)

enum DisplayStatus
{
    LCD_IN_VBLANK               = BIT(0),
    LCD_IN_HBLANK               = BIT(1),
    LCD_VCOUNT_MATCH            = BIT(2),

    LCD_VBLANK_IRQ_ENABLE       = BIT(3),
    LCD_HBLANK_IRQ_ENABLE       = BIT(4),
    LCD_VCOUNT_IRQ_ENABLE       = BIT(5),
};


// Vertical Counter

#define REG_VCOUNT      ROREG16(0x04000006)

#define VCOUNT_DISPLAY_START    0
#define VCOUNT_VBLANK_START     160


// Background Control

#define REG_BG0CNT      REG16(0x04000008)
#define REG_BG1CNT      REG16(0x0400000A)
#define REG_BG2CNT      REG16(0x0400000C)
#define REG_BG3CNT      REG16(0x0400000E)

#define BF_BG_PRIO_OFFSET 0
#define BF_BG_PRIO_LENGTH 2

#define BF_BG_SIZE_OFFSET 14
#define BF_BG_SIZE_LENGTH 2

#define BF_BG_AFF_SIZE_OFFSET 14
#define BF_BG_AFF_SIZE_LENGTH 2

enum BackgroundControl
{
    BG_PRIO_0                   = BITFIELD(BG_PRIO, 0),
    BG_PRIO_1                   = BITFIELD(BG_PRIO, 1),
    BG_PRIO_2                   = BITFIELD(BG_PRIO, 2),
    BG_PRIO_3                   = BITFIELD(BG_PRIO, 3),

    BG_PRIO_MIN                 = BG_PRIO_3,
    BG_PRIO_MAX                 = BG_PRIO_0,

    BG_MOSAIC_ENABLE            = BIT(6),

    // TODO: Naming
    BG_256_COLOR                = BIT(7),
    BG_USE_PALETTES             = !BG_256_COLOR,

    BG_AFF_WRAP                 = BIT(13),

    BG_SIZE_256x256             = BITFIELD(BG_SIZE, 0),
    BG_SIZE_512x256             = BITFIELD(BG_SIZE, 1),
    BG_SIZE_256x512             = BITFIELD(BG_SIZE, 2),
    BG_SIZE_512x512             = BITFIELD(BG_SIZE, 3),

    BG_AFF_SIZE_128x128         = BG_SIZE_256x256,
    BG_AFF_SIZE_256x256         = BG_SIZE_512x256,
    BG_AFF_SIZE_512x512         = BG_SIZE_256x512,
    BG_AFF_SIZE_1024x1024       = BG_SIZE_512x512,
};

#define BF_BG_GFX_BASE_OFFSET 2
#define BF_BG_GFX_BASE_LENGTH 2

#define BF_BG_MAP_BASE_OFFSET 8
#define BF_BG_MAP_BASE_LENGTH 5

#define BG_GFX_BASE(n)  BITFIELD(BG_GFX_BASE, n)
#define BG_MAP_BASE(n)  BITFIELD(BG_MAP_BASE, n)

typedef u16 Color;
typedef Color Palette[256];
typedef Color PaletteBank[16];

#define BG_PALETTE      (*(Palette)(MEM_PALETTE))
#define OBJ_PALETTE     (*(Palette)(MEM_PALETTE + 256))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_VIDEO_H */
