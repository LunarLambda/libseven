/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SERIAL_UART_H
#define _LIBSEVEN_SERIAL_UART_H

#error "seven/serial/uart.h is unfinished and should not be used"

#include <seven/base.h>
#include <seven/hw/serial.h>

_LIBSEVEN_EXTERN_C
//
// 0-1: Baud rate (Like above)
// 2: CTS (Clearance to Send Enable) (0 = Send always, 1 = Wait for SC=0)
// 3: Parity control (0 = Even, 1 = Odd)
// 4: Send data flag (0 = Not full, 1 = Full)
// 5: Recv data flag (0 = Not empty, 1 = Empty)
// 6: Error
// 7: Data length (0 = 7 Bit, 1 = 8 Bit)
// 8: FIFO Enable
// 9: Parity Enable
// 10: Send Enable
// 11: Recv Enable
// 14: IRQ Enable
enum SerialIOControlUART
{
};

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SERIAL_UART_H */
