# I/O Register Reference - Display Control

Defined in [seven/hw/video.h](../../include/seven/hw/video.h)

Address     | Size | Access | GBATEK  | libgba  | libtonc     | libseven
:----------:|:----:|:------:|:--------|:--------|:------------|:--------
 0400 0000  | 16   | R/W    | DISPCNT | DISPCNT | DISPCNT [¹] | DISPCNT

## Contents

Bits | Access | Description                          | C Constants
----:|:------:|:-------------------------------------|:-----------
 0-2 | R/W    | Video mode                           | VIDEO_MODE_\*
 3   | R/BIOS | Game Boy mode (0 = GBA, 1 = CGB)     | -
 4   | R/W    | Bitmap frame select                  | VIDEO_FRAME_SELECT
 5   | R/W    | Disable object processing in H-Blank | -
 6   | R/W    | Object tile mapping (1 = 1D, 0 = 2D) | VIDEO_OBJ_MAPPING_1D / VIDEO_OBJ_MAPPING_2D
 7   | R/W    | Force display blank                  | VIDEO_FORCE_BLANK
 8   | R/W    | Display background 0                 | VIDEO_BG0_ENABLE
 9   | R/W    | Display background 1                 | VIDEO_BG1_ENABLE
10   | R/W    | Display background 2                 | VIDEO_BG2_ENABLE
11   | R/W    | Display background 3                 | VIDEO_BG3_ENABLE
12   | R/W    | Display objects                      | VIDEO_OBJ_ENABLE
13   | R/W    | Enable window 0                      | VIDEO_WIN0_ENABLE
14   | R/W    | Enable window 1                      | VIDEO_WIN1_ENABLE
15   | R/W    | Enable object window                 | VIDEO_OBJ_WIN_ENABLE

## VIDEO_MODE Bitfield

Value | Description                          | C Constants
-----:|:-------------------------------------|:-----------
0     | 4 regular backgrounds                | VIDEO_MODE_REGULAR
1     | 2 regular + 1 affine background      | VIDEO_MODE_MIXED
2     | 2 affine backgrounds                 | VIDEO_MODE_AFFINE
3     | 1 240x160 16-bpp framebuffer         | VIDEO_MODE_BITMAP
4     | 2 240x160 8-bpp indexed framebuffers | VIDEO_MODE_BITMAP_INDEXED
5     | 2 160x128 16-bpp framebuffers        | VIDEO_MODE_BITMAP_SMALL

[¹]: ../registers.md#errata
