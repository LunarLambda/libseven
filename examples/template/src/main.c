#include <seven/video/prelude.h>
#include <seven/video/bg_bitmap.h>

int main(void)
{
    REG_DISPCNT = VIDEO_MODE_BITMAP | VIDEO_BG2_ENABLE;

    MODE3_FRAME[80][120] = RGB5(31,  0,  0);
    MODE3_FRAME[80][136] = RGB5( 0, 31,  0);
    MODE3_FRAME[96][120] = RGB5( 0,  0, 31);

    while (1) {}
}
