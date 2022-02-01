@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_HW_GPIO_S
.equiv   _LIBSEVEN_ASM_HW_GPIO_S, 1

.include "seven/asm/base.s"

REG   GPIODAT, 0x080000C4
REG   GPIODIR, 0x080000C6
REG   GPIOCNT, 0x080000C8

CONST GPIO_IN,  0
CONST GPIO_OUT, 1

CONST GPIO_WRITEONLY, 0
CONSt GPIO_READWRITE, 1

.endif @ !_LIBSEVEN_ASM_HW_GPIO_S

@ vim: ft=armv4 et sta sw=4 sts=8
