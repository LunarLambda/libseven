@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef _LIBSEVEN_ASM_BASE_S
.equiv  _LIBSEVEN_ASM_BASE_S, 1

.equiv REG_BASE, 0x04000000

.macro CONST id:req, v:req
    .equiv \id, \v
.endm

.macro REG id:req addr:req
    CONST REG_\id, \addr
    CONST OFF_\id, (\addr) - REG_BASE
.endm

.macro BIT id:req n:req
    CONST \id, 1 << (\n)
.endm

.macro BITS id:req n:req
    CONST \id, (1 << (\n)) - 1
.endm

.macro BITFIELD id:req sid:req value:req
    CONST \id\()_\sid, ((\value) & ((1 << BF_\id\()_LENGTH) - 1)) << BF_\id\()_OFFSET
.endm

.macro EXTFN id:req
    .extern \id
    .type   \id STT_FUNC
.endm

.endif @ !_LIBSEVEN_ASM_BASE_S

@ vim: ft=armv4 et sta sw=4 sts=8
