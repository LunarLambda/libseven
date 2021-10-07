#include <seven/prelude.h>

int main(void)
{
    irqInit(NULL);
    irqEnable(IRQ_VBLANK);

    REG_DISPSTAT = LCD_VBLANK_IRQ_ENABLE;
    REG_DISPCNT  = LCD_MODE_3 | LCD_ENABLE_BG2;

    MODE3_FRAME[80][120] = RGB5(31,  0,  0);
    MODE3_FRAME[80][136] = RGB5( 0, 31,  0);
    MODE3_FRAME[96][120] = RGB5( 0,  0, 31);

    while (1)
    {
        svcVBlankIntrWait();
    }
}
