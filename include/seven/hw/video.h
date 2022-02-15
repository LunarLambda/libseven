/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_VIDEO_H
#define _LIBSEVEN_HW_VIDEO_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

enum LCDDimensions
{
    LCD_WIDTH     = 240,
    LCD_HEIGHT    = 160,
    LCD_SCANLINES = 228,
};

#define REG_DISPCNT     REG16(0x04000000)
#define REG_DISPSTAT    REG16(0x04000004)
#define REG_VCOUNT      ROREG16(0x04000006)
#define REG_BG0CNT      REG16(0x04000008)
#define REG_BG1CNT      REG16(0x0400000A)
#define REG_BG2CNT      REG16(0x0400000C)
#define REG_BG3CNT      REG16(0x0400000E)

#define BF_LCD_MODE_OFFSET 0
#define BF_LCD_MODE_LENGTH 3

#define LCD_MODE(n)     BITFIELD(LCD_MODE, (n))

enum DisplayControl
{
    LCD_MODE_REGULAR        = LCD_MODE(0),
    LCD_MODE_MIXED          = LCD_MODE(1),
    LCD_MODE_AFFINE         = LCD_MODE(2),
    LCD_MODE_BITMAP         = LCD_MODE(3),
    LCD_MODE_BITMAP_INDEXED = LCD_MODE(4),
    LCD_MODE_BITMAP_SMALL   = LCD_MODE(5),

    LCD_FRAME_SELECT        = BIT(4),

    LCD_OBJ_MAPPING_1D      = BIT(6),
    LCD_OBJ_MAPPING_2D      = !LCD_OBJ_MAPPING_1D,

    LCD_FORCE_BLANK         = BIT(7),

    LCD_BG0_ENABLE          = BIT(8),
    LCD_BG1_ENABLE          = BIT(9),
    LCD_BG2_ENABLE          = BIT(10),
    LCD_BG3_ENABLE          = BIT(11),
    LCD_OBJ_ENABLE          = BIT(12),
    LCD_WIN0_ENABLE         = BIT(13),
    LCD_WIN1_ENABLE         = BIT(14),
    LCD_OBJ_WIN_ENABLE      = BIT(15),
};

#define BF_LCD_STATUS_VCOUNT_OFFSET 8
#define BG_LCD_STATUS_VCOUNT_LENGTH 8

#define LCD_STATUS_VCOUNT(n) BITFIELD(LCD_STATUS_VCOUNT, (n))

enum VerticalCount
{
    VCOUNT_DISPLAY_START = 0,
    VCOUNT_DISPLAY_END   = 159,
    VCOUNT_BLANK_START   = 160,
    VCOUNT_BLANK_END     = 227,
};

enum DisplayStatus
{
    LCD_STATUS_IN_VBLANK         = BIT(0),
    LCD_STATUS_IN_HBLANK         = BIT(1),
    LCD_STATUS_VCOUNT_MATCH      = BIT(2),

    LCD_STATUS_VBLANK_IRQ_ENABLE = BIT(3),
    LCD_STATUS_HBLANK_IRQ_ENABLE = BIT(4),
    LCD_STATUS_VCOUNT_IRQ_ENABLE = BIT(5),
};

#define BF_BG_PRIORITY_OFFSET 0
#define BF_BG_PRIORITY_LENGTH 2

#define BG_PRIORITY(n) BITFIELD(BG_PRIORITY, (n))

#define BF_BG_GFX_BASE_OFFSET 2
#define BF_BG_GFX_BASE_LENGTH 2

#define BG_GFX_BASE(n)  BITFIELD(BG_GFX_BASE, (n))

#define BF_BG_MAP_BASE_OFFSET 8
#define BF_BG_MAP_BASE_LENGTH 5

#define BG_MAP_BASE(n)  BITFIELD(BG_MAP_BASE, (n))

#define BF_BG_SIZE_OFFSET 14
#define BF_BG_SIZE_LENGTH 2

#define BG_SIZE(n) BITFIELD(BG_SIZE, (n))

#define BF_BG_AFFINE_SIZE_OFFSET 14
#define BF_BG_AFFINE_SIZE_LENGTH 2

#define BG_AFFINE_SIZE(n) BITFIELD(BG_AFFINE_SIZE, (n))

enum BackgroundControl
{
    BG_PRIORITY_MIN          = BG_PRIORITY(3),
    BG_PRIORITY_MAX          = BG_PRIORITY(0),

    BG_MOSAIC_ENABLE         = BIT(6),

    BG_TILE_8BPP             = BIT(7),
    BG_TILE_4BPP             = !BG_TILE_8BPP,

    BG_AFFINE_WRAP           = BIT(13),

    BG_SIZE_256x256          = BG_SIZE(0),
    BG_SIZE_512x256          = BG_SIZE(1),
    BG_SIZE_256x512          = BG_SIZE(2),
    BG_SIZE_512x512          = BG_SIZE(3),

    BG_AFFINE_SIZE_128x128   = BG_AFFINE_SIZE(0),
    BG_AFFINE_SIZE_256x256   = BG_AFFINE_SIZE(1),
    BG_AFFINE_SIZE_512x512   = BG_AFFINE_SIZE(2),
    BG_AFFINE_SIZE_1024x1024 = BG_AFFINE_SIZE(3),
};

// TODO: Move these?
typedef u16 Color;
typedef Color Palette[256];
typedef Color PaletteBank[16];

#define BG_PALETTE       (*(Palette*)(MEM_PALETTE))
#define OBJ_PALETTE      (*(Palette*)(MEM_PALETTE + 256))

#define BG_PALETTE_BANK  (*(PalleteBank(*)[16])(MEM_PALETTE))
#define OBJ_PALETTE_BANK (*(PaletteBank(*)[16])(MEM_PALETTE + 256))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_VIDEO_H */
