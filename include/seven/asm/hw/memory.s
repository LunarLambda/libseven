@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_HW_MEMORY_S
.equiv   _LIBSEVEN_ASM_HW_MEMORY_S, 1

.include "seven/asm/base.s"

CONST MEM_BIOS,         0
CONST MEM_BIOS_SIZE,    0x4000

CONST MEM_EWRAM,        0x02000000
CONST MEM_EWRAM_SIZE,   0x40000

CONST MEM_IWRAM,        0x03000000
CONST MEM_IWRAM_SIZE,   0x8000

CONST MEM_IO,           0x04000000
CONST MEM_IO_SIZE,      0x020C

CONST MEM_PALETTE,      0x05000000
CONST MEM_PALETTE_SITE, 0x400

CONST MEM_VRAM,         0x06000000
CONST MEM_VRAM_SIZE,    0x18000

CONST MEM_OAM,          0x07000000
CONST MEM_OAM_SIZE,     0x400

CONST MEM_ROM,          0x08000000
CONST MEM_ROM_SIZE,     0x02000000

CONST MEM_SRAM,         0x0E000000
CONST MEM_SRAM_SIZe,    0x8000

.endif @ !_LIBSEVEN_ASM_HW_MEMORY_S

@ vim: ft=armv4 et sta sw=4 sts=8
