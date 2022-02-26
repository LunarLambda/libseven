# I/O Register Reference - Display Control

Defined in [seven/hw/video.h](../../include/seven/hw/video.h)

Address     | Size | Access | GBATEK  | libgba  | libtonc     | libseven
:----------:|:----:|:------:|:--------|:--------|:------------|:--------
 0400 0000  | 16   | R/W    | DISPCNT | DISPCNT | DISPCNT [¹] | DISPCNT

Bits | Access | Description                          | C Constant
----:|:------:|:-------------------------------------|:----------
 0-2 | R/W    | Video mode                           | LCD_MODE_\*
 3   | R/BIOS | Game Boy mode (0 = GBA, 1 = CGB)     | -
 4   | R/W    | Bitmap frame select                  | LCD_FRAME_SELECT
 5   | R/W    | Disable object processing in H-Blank | -
 6   | R/W    | Object tile mapping (1 = 1D, 0 = 2D) | LCD_OBJ_MAPPING_1D / LCD_OBJ_MAPPING_2D
 7   | R/W    | Force display blank                  | LCD_FORCE_BLANK
 8   | R/W    | Display background 0                 | LCD_BG0_ENABLE
 9   | R/W    | Display background 1                 | LCD_BG1_ENABLE
10   | R/W    | Display background 2                 | LCD_BG2_ENABLE
11   | R/W    | Display background 3                 | LCD_BG3_ENABLE
12   | R/W    | Display objects                      | LCD_OBJ_ENABLE
13   | R/W    | Enable window 0                      | LCD_WIN0_ENABLE
14   | R/W    | Enable window 1                      | LCD_WIN1_ENABLE
15   | R/W    | Enable object window                 | LCD_OBJ_WIN_ENABLE

## LCD_MODE Bitfield

Value | C Constant
-----:|:----------
0     | LCD_MODE_REGULAR
1     | LCD_MODE_MIXED
2     | LCD_MODE_AFFINE
3     | LCD_MODE_BITMAP
4     | LCD_MODE_BITMAP_INDEXED
5     | LCD_MODE_BITMAP_SMALL

[¹]: ../registers.md#errata
