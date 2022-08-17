@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.syntax         unified
.cpu            arm7tdmi

.include        "macros.s"
.include        "seven/asm/base.s"

CONST N_OVERLAYS, 10

rodata IWRAM_OVERLAYS
    .word       __iwram_overlay_vma
    .word       __load_start_iwram0
    .word       __load_stop_iwram0
    .word       __load_start_iwram1
    .word       __load_stop_iwram1
    .word       __load_start_iwram2
    .word       __load_stop_iwram2
    .word       __load_start_iwram3
    .word       __load_stop_iwram3
    .word       __load_start_iwram4
    .word       __load_stop_iwram4
    .word       __load_start_iwram5
    .word       __load_stop_iwram5
    .word       __load_start_iwram6
    .word       __load_stop_iwram6
    .word       __load_start_iwram7
    .word       __load_stop_iwram7
    .word       __load_start_iwram8
    .word       __load_stop_iwram8
    .word       __load_start_iwram9
    .word       __load_stop_iwram9
endr

rodata EWRAM_OVERLAYS
    .word       __ewram_overlay_vma
    .word       __load_start_ewram0
    .word       __load_stop_ewram0
    .word       __load_start_ewram1
    .word       __load_stop_ewram1
    .word       __load_start_ewram2
    .word       __load_stop_ewram2
    .word       __load_start_ewram3
    .word       __load_stop_ewram3
    .word       __load_start_ewram4
    .word       __load_stop_ewram4
    .word       __load_start_ewram5
    .word       __load_stop_ewram5
    .word       __load_start_ewram6
    .word       __load_stop_ewram6
    .word       __load_start_ewram7
    .word       __load_stop_ewram7
    .word       __load_start_ewram8
    .word       __load_stop_ewram8
    .word       __load_start_ewram9
    .word       __load_stop_ewram9
endr

fn overlayInitIwram thumb
    movs        r3, #0
    cmp         r0, #N_OVERLAYS
    bge         1f

    ldr         r3, =IWRAM_OVERLAYS
    ldm         r3!, {r2}
    lsls        r0, r0, #3
    adds        r3, r3, r0
    ldm         r3!, {r0, r1}

    bne         overlayCopy

1:
    
    bx          lr
endfn

fn overlayInitIwram thumb
    movs        r3, #0
    cmp         r0, #N_OVERLAYS
    bge         1f

    ldr         r1, =EWRAM_OVERLAYS
    ldm         r1!, {r3}
    lsls        r0, r0, #3
    adds        r1, r1, r0
    ldm         r1!, {r1, r2}
    subs        r0, r2, r1

    bne         overlayCopy

1:
    bx          lr
endfn

fn overlayCopy thumb local
1:
    ldm         r1!, {r3}
    stm         r0!, {r3}
    cmp         r1, r2
    blt         1b

    pop         {r4, r5}
    bx          lr
endfn

@ vim: ft=armv4 et sta sw=4 sts=8
