#include <seven/prelude.h>

void vblank_callback(u16 irqs)
{
    BG_PALETTE[0] += 1;
}

int main(void)
{
    // Set up the necessary interrupt handling
    irqInitDefault();
    irqEnableFull(IRQ_VBLANK);
    irqCallbackSet(IRQ_VBLANK, vblank_callback, 0);

    // Clear the force-blank bit
    REG_DISPCNT = 0;

    while (1)
    {
        // Wait for V-sync
        svcVBlankIntrWait();
    }
}
