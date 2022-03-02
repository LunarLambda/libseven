@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"
.include        "seven/asm/hw/video.s"

@ void* bmpSwapBuffers(void)
@
fn bmpSwapBuffers thumb
    @ r0 = REG_DISCPNT
    @ r1 = LCD_FRAME_SELECT
    movs        r1, LCD_FRAME_SELECT
    lsls        r0, r1, #22

    @ r2 = DISPCNT ^ LCD_FRAME_SELECT
    ldrh        r2, [r0]
    eors        r2, r2, r1
    strh        r2, [r0]

    @ r0 = MEM_VRAM
    movs        r0, #6
    lsls        r0, r0, #24

    @ Is flipped?
    tst         r2, r1
    bne         .Llsb_noadd

    @ r0 += 0xA000
    movs        r2, #0xA
    lsls        r2, r2, #12
    adds        r0, r0, r2

.Llsb_noadd:
    bx          lr
endfn

@ void* bmpInitMode3(void)
@
fn bmpInitMode3 thumb
    @ r0 = REG_DISCPNT
    @ r1 = LCD_BG2_ENABLE
    movs        r0, #4
    lsls        r1, r0, #8
    lsls        r0, r0, #24

    @ r1 = LCD_BG2_ENABLE | LCD_MODE_3
    adds        r1, r1, LCD_MODE_3

    @ REG_DISCPNT = r1
    strh        r1, [r0]
    @ Reset REG_BG2CNT
    strh        r0, [r0, #12]

    @ return MEM_VRAM;
    movs        r0, #6
    lsls        r0, r0, #24
    bx          lr
endfn

@ void* bmpInitMode4(void)
@
fn bmpInitMode4 thumb
    @ r0 = REG_DISCPNT
    @ r1 = LCD_BG2_ENABLE
    movs        r0, #4
    lsls        r1, r0, #8
    lsls        r0, r0, #24

    @ r1 = LCD_BG2_ENABLE | LCD_MODE_4
    adds        r1, r1, LCD_MODE_4

    @ REG_DISCPNT = r1
    strh        r1, [r0]
    @ Reset REG_BG2CNT
    strh        r0, [r0, #12]

    @ return MEM_VRAM;
    movs        r0, #6
    lsls        r0, r0, #24
    bx          lr
endfn

@ void* bmpInitMode5(void)
@
fn bmpInitMode5 thumb
    @ r0 = REG_DISCPNT
    @ r1 = LCD_BG2_ENABLE
    movs        r0, #4
    lsls        r1, r0, #8
    lsls        r0, r0, #24

    @ r1 = LCD_BG2_ENABLE | LCD_MODE_5
    adds        r1, r1, LCD_MODE_5

    @ REG_DISCPNT = r1
    strh        r1, [r0]
    @ Reset REG_BG2CNT
    strh        r0, [r0, #12]

    @ return MEM_VRAM;
    movs        r0, #6
    lsls        r0, r0, #24
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
