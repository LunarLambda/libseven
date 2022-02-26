#include <seven/prelude.h>

int main(void)
{
    // Set up the necessary interrupt handling
    irqInitDefault();
    irqEnableFull(IRQ_VBLANK);

    // Clear the force-blank bit
    REG_DISPCNT = 0;

    while (1)
    {
        // Wait for V-sync
        svcVBlankIntrWait();

        // Update the background color for the next frame
        BG_PALETTE[0] += 1;
    }
}
