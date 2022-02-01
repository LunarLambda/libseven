@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_HW_WAITSTATES_S
.equiv   _LIBSEVEN_ASM_HW_WAITSTATES_S, 1

.include "seven/asm/base.s"

REG     WAITCNT,                0x04000204

CONST   BF_WAIT_SRAM_OFFSET,    0
CONST   BF_WAIT_SRAM_LENGTH,    2

CONST   BF_WAIT_ROM_N_OFFSET,   2
CONST   BF_WAIT_ROM_N_LENGTH,   2

CONST   BF_WAIT_ROM_S_OFFSET,   4
CONST   BF_WAIT_ROM_S_LENGTH,   1

BITFIELD WAIT_SRAM 4, 0
BITFIELD WAIT_SRAM 3, 1
BITFIELD WAIT_SRAM 2, 2
BITFIELD WAIT_SRAM 8, 3

BITFIELD WAIT_ROM_N 4, 0
BITFIELD WAIT_ROM_N 3, 1
BITFIELD WAIT_ROM_N 2, 2
BITFIELD WAIT_ROM_N 8, 3

BITFIELD WAIT_ROM_S 2, 0
BITFIELD WAIT_ROM_S 1, 1

BIT      WAIT_PREFETCH_ENABLE, 14

.endif @ !_LIBSEVEN_ASM_HW_WAITSTATES_S

@ vim: ft=armv4 et sta sw=4 sts=8
