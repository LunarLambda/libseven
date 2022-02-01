@
@ This Source Code Form is subject to the terms of the Mozilla Public
@ License, v. 2.0. If a copy of the MPL was not distributed with this
@ file, You can obtain one at https://mozilla.org/MPL/2.0/.
@

.ifndef  _LIBSEVEN_ASM_HW_INPUT_S
.equiv   _LIBSEVEN_ASM_HW_INPUT_S, 1

.include "seven/asm/base.s"

REG     KEYINPUT,               0x04000130
REG     KEYCNT,                 0x04000132

BIT     KEY_A,                  0
BIT     KEY_B,                  1
BIT     KEY_SELECT,             2
BIT     KEY_START,              3
BIT     KEY_RIGHT,              4
BIT     KEY_LEFT,               5
BIT     KEY_UP,                 6
BIT     KEY_DOWN,               7
BIT     KEY_R,                  8
BIT     KEY_L,                  9

CONST   KEYS_DPAD_X,            KEY_LEFT    | KEY_RIGHT
CONST   KEYS_DPAD_Y,            KEY_UP      | KEY_DOWN
CONST   KEYS_DPAD,              KEYS_DPAD_X | KEYS_DPAD_Y
CONST   KEYS_AB,                KEY_A       | KEY_B
CONST   KEYS_LR,                KEY_L       | KEY_R
CONST   KEYS_STARTSELECT,       KEY_START   | KEY_SELECT
CONST   KEYS_BUTTONS,           KEYS_AB     | KEYS_LR     | KEYS_STARTSELECT
CONST   KEYS_ALL                KEYS_DPAD   | KEYS_BUTTONS

CONST   KEY_INDEX_A,            0
CONST   KEY_INDEX_B,            1
CONST   KEY_INDEX_SELECT,       2
CONST   KEY_INDEX_START,        3
CONST   KEY_INDEX_RIGHT,        4
CONST   KEY_INDEX_LEFT,         5
CONST   KEY_INDEX_UP,           6
CONST   KEY_INDEX_DOWN,         7
CONST   KEY_INDEX_R,            8
CONST   KEY_INDEX_L,            9

BIT     KEY_IRQ_ENABLE,         14
BIT     KEY_IRQ_PRESS_ALL,      15
CONST   KEY_IRQ_PRESS_ANY,      !KEY_IRQ_PRESS_ALL

EXTFN   inputPoll
EXTFN   inputState
EXTFN   inputKeysPressed
EXTFN   inputKeysReleased
EXTFN   inputKeysDown
EXTFN   inputKeysUp
EXTFN   inputAxisX
EXTFN   inputAxisY
EXTFN   inputAxisLR
EXTFN   inputAxisAB

.endif @ !_LIBSEVEN_ASM_HW_INPUT_S

@ vim: ft=armv4 et sta sw=4 sts=8
