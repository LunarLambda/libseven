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

extern u16 inputKeysPressed(void)
{
    return ~keyinput_last & keyinput;
}

extern u16 inputKeysReleased(void)
{
    return keyinput_last & ~keyinput;
}

extern u16 inputKeysDown(void)
{
    return keyinput;
}
