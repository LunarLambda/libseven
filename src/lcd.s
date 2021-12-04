.syntax         unified
.cpu            arm7tdmi

.include        "asm_base.s"

.set REG_IME,           0x04000208
.set REG_DISPCNT,       0x04000000
.set REG_BG2CNT,        0x04000000
.set MEM_VRAM,          0x06000000
.set LCD_FRAME_SELECT,  0x10
.set LCD_BG2_ENABLE,    0x400
.set LCD_MODE_3,        0x3
.set LCD_MODE_4,        0x4
.set LCD_MODE_5,        0x5

func lcdSwapBuffers thumb
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
endf

func lcdInitMode3 thumb
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
endf

func lcdInitMode4 thumb
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
endf

func lcdInitMode5 thumb
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
endf

@ vim:ft=armv4 et sta sw=4 sts=8
