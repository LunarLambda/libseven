@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_PRELUDE_S
.equiv   _LIBSEVEN_ASM_PRELUDE_S, 1

.include "seven/asm/base.s"
.include "seven/asm/hw/input.s"
.include "seven/asm/hw/irq.s"
.include "seven/asm/hw/memory.s"
.include "seven/asm/hw/svc.s"

.endif @ !_LIBSEVEN_ASM_PRELUDE_S

@ vim: ft=armv4 et sta sw=4 sts=8
