/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_HW_INPUT_H
#define _LIBSEVEN_HW_INPUT_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

// Keypad input register. Reports held keys as active-low bits.
//
#define REG_KEYINPUT    VOLADDR(0x04000130, const u16)

// Keypad control register. Allows configuring the keypad IRQ.
//
#define REG_KEYCNT      VOLADDR(0x04000132, u16)

// Key bits as used by KEYINPUT and KEYCNT.
enum Key
{
    KEY_A               = BIT(0),
    KEY_B               = BIT(1),
    KEY_SELECT          = BIT(2),
    KEY_START           = BIT(3),
    KEY_RIGHT           = BIT(4),
    KEY_LEFT            = BIT(5),
    KEY_UP              = BIT(6),
    KEY_DOWN            = BIT(7),
    KEY_R               = BIT(8),
    KEY_L               = BIT(9),
};

// Groupings of key bits.
enum KeyGroup
{
    KEYS_DPAD_X         = KEY_LEFT      | KEY_RIGHT,
    KEYS_DPAD_Y         = KEY_UP        | KEY_DOWN,
    KEYS_DPAD           = KEYS_DPAD_X   | KEYS_DPAD_Y,
    KEYS_AB             = KEY_A         | KEY_B,
    KEYS_LR             = KEY_L         | KEY_R,
    KEYS_STARTSELECT    = KEY_START     | KEY_SELECT,
    KEYS_BUTTONS        = KEYS_AB       | KEYS_LR       | KEYS_STARTSELECT,
    KEYS_ALL            = KEYS_DPAD     | KEYS_BUTTONS,
};

// Bit indices of keys bits.
enum KeyIndex
{
    KEY_INDEX_A,
    KEY_INDEX_B,
    KEY_INDEX_SELECT,
    KEY_INDEX_START,
    KEY_INDEX_RIGHT,
    KEY_INDEX_LEFT,
    KEY_INDEX_UP,
    KEY_INDEX_DOWN,
    KEY_INDEX_R,
    KEY_INDEX_L,
    KEY_INDEX_MAX,
};

enum KeyIRQ
{
    KEY_IRQ_ENABLE       = BIT(14),
    KEY_IRQ_PRESS_ALL    = BIT(15),
    KEY_IRQ_PRESS_ANY    = !KEY_IRQ_PRESS_ALL,
};

// Updates the internal keypad state. Should be called once per frame.
extern void inputPoll(void);

// Gets the internal keypad state. The lower halfword contains the current
// input state, the upper halfword contains the last input state.
extern u32 inputState(void);

// Returns the keys that were pressed this frame. ("Rising egde")
extern u16 inputKeysPressed(u16 keys);

// Returns the keys that were released this frame. ("Falling edge")
extern u16 inputKeysReleased(u16 keys);

// Returns the keys that are being held this frame.
extern u16 inputKeysDown(u16 keys);

// Returns the keys that are not being held this frame.
extern u16 inputKeysUp(u16 keys);

// Gets the state of the Dpad X-axis.
// -1: Left
//  0: None
//  1: Right
extern i32 inputAxisX(void);

// Gets the state of the Dpad Y-axis.
// -1: Up
//  0: None
//  1: Down
extern i32 inputAxisY(void);

// Gets the state of the shoulder button axis.
// -1: L
//  0: None/Both
//  1: R
extern i32 inputAxisLR(void);

// Gets the state of the face button axis.
// -1: B
//  0: None/Both
//  1: A
extern i32 inputAxisAB(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_INPUT_H */
