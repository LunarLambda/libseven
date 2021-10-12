#ifndef _LIBSEVEN_HW_VIDEO_H
#define _LIBSEVEN_HW_VIDEO_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// Display Control

#define REG_DISPCNT             REG16(0x04000000)

enum DisplayControl
{
    LCD_MODE_0                  = BITFIELD(0, 3, 0),
    LCD_MODE_1                  = BITFIELD(0, 3, 1),
    LCD_MODE_2                  = BITFIELD(0, 3, 2),
    LCD_MODE_3                  = BITFIELD(0, 3, 3),
    LCD_MODE_4                  = BITFIELD(0, 3, 4),
    LCD_MODE_5                  = BITFIELD(0, 3, 5),

    LCD_MODE_REGULAR            = LCD_MODE_0,
    LCD_MODE_MIXED              = LCD_MODE_1,
    LCD_MODE_AFFINE             = LCD_MODE_2,
    LCD_MODE_BITMAP             = LCD_MODE_3,
    LCD_MODE_BITMAP256          = LCD_MODE_4,
    LCD_MODE_BITMAP_SMALL       = LCD_MODE_5,

    LCD_CGB_MODE                = BIT(3),

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

enum BackgroundControl
{
    BG_PRIO_0                   = BITFIELD(0, 2, 0),
    BG_PRIO_1                   = BITFIELD(0, 2, 1),
    BG_PRIO_2                   = BITFIELD(0, 2, 2),
    BG_PRIO_3                   = BITFIELD(0, 2, 3),

    BG_PRIO_MIN                 = BG_PRIO_3,
    BG_PRIO_MAX                 = BG_PRIO_0,

    BG_MOSAIC_ENABLE            = BIT(6),

    // TODO: Naming
    BG_256_COLOR                = BIT(7),
    BG_USE_PALETTES             = !BG_256_COLOR,

    // TODO: Naming
    BG_AFF_OVERFLOW_WRAP        = BIT(13),
    BG_AFF_OVERFLOW_TRANS       = !BG_AFF_OVERFLOW_WRAP,

    BG_SIZE_256x256             = BITFIELD(14, 2, 0),
    BG_SIZE_512x256             = BITFIELD(14, 2, 1),
    BG_SIZE_256x512             = BITFIELD(14, 2, 2),
    BG_SIZE_512x512             = BITFIELD(14, 2, 3),

    BG_AFF_SIZE_128x128         = BG_SIZE_256x256,
    BG_AFF_SIZE_256x256         = BG_SIZE_512x256,
    BG_AFF_SIZE_512x512         = BG_SIZE_256x512,
    BG_AFF_SIZE_1024x1024       = BG_SIZE_512x512,
};

#define BG_GFX_BASE(n)  BITFIELD(2, 2, n)
#define BG_MAP_BASE(n)  BITFIELD(8, 5, n)


// Background Scroll

#define REG_BG0HOFS     REG16(0x04000010)
#define REG_BG0VOFS     REG16(0x04000012)
#define REG_BG1HOFS     REG16(0x04000014)
#define REG_BG1VOFS     REG16(0x04000016)
#define REG_BG2HOFS     REG16(0x04000018)
#define REG_BG2VOFS     REG16(0x0400001A)
#define REG_BG3HOFS     REG16(0x0400001C)
#define REG_BG3VOFS     REG16(0x0400001E)


// Background Affine Transform Parameters

#define REG_BG2PA       REG16(0x04000020)
#define REG_BG2PB       REG16(0x04000022)
#define REG_BG2PC       REG16(0x04000024)
#define REG_BG2PD       REG16(0x04000026)

#define REG_BG2X        REG32(0x04000028)
#define REG_BG2Y        REG32(0x0400002C)

#define REG_BG3PA       REG16(0x04000030)
#define REG_BG3PB       REG16(0x04000032)
#define REG_BG3PC       REG16(0x04000034)
#define REG_BG3PD       REG16(0x04000036)

#define REG_BG3X        REG32(0x04000038)
#define REG_BG3Y        REG32(0x0400003C)


// Windows

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
    WIN_BG0_ENABLE       = BIT(0),
    WIN_BG1_ENABLE       = BIT(1),
    WIN_BG2_ENABLE       = BIT(2),
    WIN_BG3_ENABLE       = BIT(3),
    WIN_OBJ_ENABLE       = BIT(4),
    WIN_BLEND_ENABLE     = BIT(5),
};

#define WINDOW_DIM(l, h)        ((((l) & 255) << 8) | ((h) & 255))


// Mosaic

#define REG_MOSAIC      REG16(0x0400004C)


// Blending

#define REG_BLDCNT      REG16(0x04000050)

enum BlendControl
{
    BLD_TARGET_BG0      = BIT(0),
    BLD_TARGET_BG1      = BIT(1),
    BLD_TARGET_BG2      = BIT(2),
    BLD_TARGET_BG3      = BIT(3),
    BLD_TARGET_OBJ      = BIT(4),
    BLD_TARGET_BD       = BIT(5),

    BLD_MODE_OFF        = BITFIELD(6, 2, 0),
    BLD_MODE_ALPHA      = BITFIELD(6, 2, 1),
    BLD_MODE_WHITE      = BITFIELD(6, 2, 2),
    BLD_MODE_BLACK      = BITFIELD(6, 2, 3),

    // Only used with BLD_MODE_ALPHA
    BLD_TARGET2_BG0      = BIT(8),
    BLD_TARGET2_BG1      = BIT(9),
    BLD_TARGET2_BG2      = BIT(10),
    BLD_TARGET2_BG3      = BIT(11),
    BLD_TARGET2_OBJ      = BIT(12),
    BLD_TARGET2_BD       = BIT(13),
};

// TODO: BLDALPHA defines
#define REG_BLDALPHA    REG16(0x04000052)
// TODO: different name?
#define REG_BLDY        REG16(0x04000054)

typedef u16 Color;

#define RGB5(r, g, b) \
    (Color)(BITFIELD(0, 5, (r)) | BITFIELD(5, 5, (g)) | BITFIELD(10, 5, (b)))

#define RGB8(r, g, b) \
    RGB5((r) >> 3, (g) >> 3, (b) >> 3)

#define BG_PALETTE      (*(Color(*)[256])(MEM_PALETTE))
#define OBJ_PALETTE     (*(Color(*)[256])(MEM_PALETTE + 256))

#define MODE3_WIDTH     240
#define MODE3_HEIGHT    160

typedef Color Mode3Line[MODE3_WIDTH];

// TODO: Naming
#define MODE3_FRAME     (*(Mode3Line(*)[MODE3_HEIGHT])(MEM_VRAM))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_VIDEO_H */
