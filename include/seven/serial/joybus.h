/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SERIAL_JOYBUS_H
#define _LIBSEVEN_SERIAL_JOYBUS_H

#error "seven/serial/joybus.h is unfinished and should not be used"

#include <seven/base.h>
#include <seven/hw/serial.h>

_LIBSEVEN_EXTERN_C

// Joy BUS Control
#define REG_JOYCNT      VOLADDR(0x04000140, u16)
// Send/Receive for JOY Bus
#define REG_JOYRECV     VOLADDR(0x04000150, u32)
#define REG_JOYSEND     VOLADDR(0x04000154, u32)
// JOY Bus Status
#define REG_JOYSTAT     VOlADDR(0x04000158, u16)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SERIAL_JOYBUS_H */
