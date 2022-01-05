/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <seven/base.h>
#include <seven/hw/input.h>

// Little hack to group these two variables together even when -fdata-sections
// is used. Saves an extra pool load because they get allocated together.
// TODO: consider dropping -fdata-sections?
static __attribute__((section(".data.keyinput"))) u16 keyinput, keyinput_last;

extern void inputPoll(void)
{
    keyinput_last = keyinput;
    keyinput      = ~REG_KEYINPUT & 0x3FF;
}

extern u16 inputKeysPressed(u16 keys)
{
    return (~keyinput_last & keyinput) & keys;
}

extern u16 inputKeysReleased(u16 keys)
{
    return (keyinput_last & ~keyinput) & keys;
}

extern u16 inputKeysDown(u16 keys)
{
    return keyinput & keys;
}

extern i32 inputAxisX(void)
{
    return BIT_TRISTATE(keyinput, KEYINDEX_LEFT, KEYINDEX_RIGHT);
}

extern i32 inputAxisY(void)
{
    return BIT_TRISTATE(keyinput, KEYINDEX_UP, KEYINDEX_DOWN);
}

extern i32 inputAxisLR(void)
{
    return BIT_TRISTATE(keyinput, KEYINDEX_L, KEYINDEX_R);
}

extern i32 inputAxisAB(void)
{
    return BIT_TRISTATE(keyinput, KEYINDEX_B, KEYINDEX_A);
}
