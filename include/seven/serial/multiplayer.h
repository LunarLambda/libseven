/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SERIAL_MULTIPLAYER_H
#define _LIBSEVEN_SERIAL_MULTIPLAYER_H

#error "seven/serial/multiplayer.h is unfinished and should not be used"

#include <seven/base.h>
#include <seven/hw/serial.h>

_LIBSEVEN_EXTERN_C

// Send for Multiplayer
#define REG_SIODATA16   VOLADDR(0x0400012A, u16)

// Receive for Multiplayer
#define REG_SIOMULTI0   VOLADDR(0x04000120, u16)
#define REG_SIOMULTI1   VOLADDR(0x04000122, u16)
#define REG_SIOMULTI2   VOLADDR(0x04000124, u16)
#define REG_SIOMULTI3   VOLADDR(0x04000126, u16)

// 0-1: Baud rate (9600, 38400, 57600, 115200)
// 2: SI Pin (0 = Parent, 1 = Child)
// 3: SD Pin (0 = Error, 1 = Everyone Ready)
// 4-5: Client ID (0 = Server)
// 6: Error
// 7: Start/Busy (0 = Inactive, 1 = Start/Busy)
// 14: IRQ Enable
enum SerialIOControlMultiplayer
{

};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SERIAL_MULTIPLAYER_H */
