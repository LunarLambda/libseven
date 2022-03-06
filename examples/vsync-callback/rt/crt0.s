@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.section        .rom_header,"ax",%progbits
.align 2
.arm
_start:
    b           entrypoint      @ ROM entry point
                                @ Nintendo logo data
    .byte       0x24, 0xFF, 0xAE, 0x51, 0x69, 0x9A, 0xA2, 0x21
    .byte       0x3D, 0x84, 0x82, 0x0A, 0x84, 0xE4, 0x09, 0xAD
    .byte       0x11, 0x24, 0x8B, 0x98, 0xC0, 0x81, 0x7F, 0x21
    .byte       0xA3, 0x52, 0xBE, 0x19, 0x93, 0x09, 0xCE, 0x20
    .byte       0x10, 0x46, 0x4A, 0x4A, 0xF8, 0x27, 0x31, 0xEC
    .byte       0x58, 0xC7, 0xE8, 0x33, 0x82, 0xE3, 0xCE, 0xBF
    .byte       0x85, 0xF4, 0xDF, 0x94, 0xCE, 0x4B, 0x09, 0xC1
    .byte       0x94, 0x56, 0x8A, 0xC0, 0x13, 0x72, 0xA7, 0xFC
    .byte       0x9F, 0x84, 0x4D, 0x73, 0xA3, 0xCA, 0x9A, 0x61
    .byte       0x58, 0x97, 0xA3, 0x27, 0xFC, 0x03, 0x98, 0x76
    .byte       0x23, 0x1D, 0xC7, 0x61, 0x03, 0x04, 0xAE, 0x56
    .byte       0xBF, 0x38, 0x84, 0x00, 0x40, 0xA7, 0x0E, 0xFD
    .byte       0xFF, 0x52, 0xFE, 0x03, 0x6F, 0x95, 0x30, 0xF1
    .byte       0x97, 0xFB, 0xC0, 0x85, 0x60, 0xD6, 0x80, 0x25
    .byte       0xA9, 0x63, 0xBE, 0x03, 0x01, 0x4E, 0x38, 0xE2
    .byte       0xF9, 0xA2, 0x34, 0xFF, 0xBB, 0x3E, 0x03, 0x44
    .byte       0x78, 0x00, 0x90, 0xCB, 0x88, 0x11, 0x3A, 0x94
    .byte       0x65, 0xC0, 0x7C, 0x63, 0x87, 0xF0, 0x3C, 0xAF
    .byte       0xD6, 0x25, 0xE4, 0x8B, 0x38, 0x0A, 0xAC, 0x72
    .byte       0x21, 0xD4, 0xF8, 0x07
    @ CHECKSUM AREA BEGIN
    .zero       12              @ Game title
    .zero       4               @ Game code
    .zero       2               @ Maker code
    .byte       0x96            @ Mandatory
    .zero       1               @ Device code
    .zero       1               @ Device type
    .zero       7               @ Reserved
    .zero       1               @ Game version
    @ CHECKSUM AREA END
    .byte       0 - 0x96 - 0x19 @ Checksum
    .zero       2               @ Reserved
    b           entrypoint      @ Multiboot entry point
_boot_type:
    .zero       1               @ Boot type
_boot_client:
    .zero       1               @ Client number
    .zero       26              @ Reserved
    b           entrypoint      @ JOY Bus entry point

.align 2
.arm
entrypoint:
    add         r0, pc, #1
    bx          r0
.thumb
    @ TODO: Stuff like boot type check for multiboot and such (LR holds load address)
    ldr         r3, =REG_DMA3

    @ .iwram section
    ldr         r0, =__iwram_lma
    ldr         r1, =__iwram_vma
    ldr         r2, =__iwram_dma
    bl          dma_copy

    @ .iwram0 section
    ldr         r0, =__load_start_iwram0
    ldr         r1, =__iwram_overlay_vma
    ldr         r2, =__iwram_overlay_dma
    bl          dma_copy

    @ .iwram_bss section
    ldr         r0, =dma_zero
    ldr         r1, =__iwram_bss_vma
    ldr         r2, =__iwram_bss_dma
    @ bl          dma_copy
    svc         #SVC_CPUSET

    @ .ewram section
    ldr         r0, =__ewram_lma
    ldr         r1, =__ewram_vma
    ldr         r2, =__ewram_dma
    bl          dma_copy

    @ .ewram0 section
    ldr         r0, =__load_start_ewram0
    ldr         r1, =__ewram_overlay_vma
    ldr         r2, =__ewram_overlay_dma
    bl          dma_copy

    @ .ewram_bss section
    ldr         r0, =dma_zero
    ldr         r1, =__ewram_bss_vma
    ldr         r2, =__ewram_bss_dma
    @ bl          dma_copy
    svc         #SVC_CPUSET

    @ .preinit_array section
    ldr         r4, =__preinit_array_start
    ldr         r5, =__preinit_array_end
    bl          init_array

    @ .init_array section
    ldr         r4, =__init_array_start
    ldr         r5, =__init_array_end
    bl          init_array

    @ main(0, NULL,NULL)
    movs        r0, #0 @ argc
    movs        r1, #0 @ argv
    movs        r2, #0 @ envp
    ldr         r3, =main
    bl          bx_r3
    movs        r7, r0

    @ .fini_array section
    ldr         r4, =__fini_array_start
    ldr         r5, =__fini_array_end
    bl          fini_array

    @ exit()
    movs        r0, r7
    ldr         r3, =exit
    bl          bx_r3

_exit:
    @ Disable IRQs and halt
    ldr         r3, =REG_IME
    strh        r3, [r3]
    1: b        1b

.align 2
dma_zero:
    .word       0

dma_copy:
    @ NOTE: This checks against a non-zero section size.
    @ In the case of an EWRAM section spanning all of EWRAM (256K),
    @ The lower 16-bit will be zero. This works fine for the DMA,
    @ since the lower 5 bit of DMACNT are unused.
    @ That's why we shift 15, not 16.
    lsls        r4, r2, #15
    beq         dma_skip
    stm         r3!, {r0, r1, r2}
    subs        r3, r3, #12
dma_skip:
    bx          lr

init_array:
    mov         r6, lr
    cmp         r4, r5
    beq         init_skip
init_loop:
    ldr         r3, [r4]
    bl          bx_r3
    adds        r4, r4, #4
    cmp         r4, r5
    bne         init_loop
init_skip:
    bx          r6

bx_r3:
    bx          r3

fini_array:
    mov         r6, lr
    cmp         r5, r4
    beq         fini_skip
fini_loop:
    subs        r5, r5, #4
    ldr         r3, [r5]
    bl          bx_r3
    cmp         r5, r4
    bne         fini_loop
fini_skip:
    bx          r6

pool: .pool

.equiv          REG_DMA3,       0x040000D4
.equiv          REG_IME,        0x04000208
.equiv          SVC_CPUSET,     11

.global         _start, _exit, _boot_type, _boot_client

@ vim: ft=armv4 et sta sw=4 sts=8
