#include <seven_prelude.h>

int main(void)
{
    irqInit(NULL);
    irqEnable(IRQ_VBLANK);

    REG_DISPSTAT = LCD_VBLANK_IRQ_ENABLE;
    REG_DISPCNT  = LCD_MODE_3 | LCD_ENABLE_BG2;

    volatile u16 *fb = MEM_VRAM;

    fb[120+80*240] = 0x001F;
    fb[136+80*240] = 0x03E0;
    fb[120+96*240] = 0x7C00;

    while (1) {
        svcVBlankIntrWait();
    }
}
