#include <seven_base.h>
#include <seven_input.h>
#include <seven_irq.h>

// Little hack to group these two variables together even when -fdata-sections
// is used. Saves an extra pool load because they get allocated together.
static __attribute__((section(".data.keyinput"))) u16 keyinput, keyinput_last;

extern void inputPoll(void)
{
    keyinput_last = keyinput;
    keyinput      = ~REG_KEYINPUT & 0x3FF;
}

extern u16 inputKeysDown(void)
{
    return ~keyinput_last & keyinput;
}

extern u16 inputKeysUp(void)
{
    return keyinput_last & ~keyinput;
}

extern u16 inputKeysHeld(void)
{
    return keyinput;
}

extern void inputSetKeyIRQ(u16 keys, u16 op)
{
    REG_KEYCNT = keys | op | KEY_IRQ_ENABLE;
}
