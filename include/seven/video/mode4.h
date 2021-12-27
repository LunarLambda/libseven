#ifndef _LIBSEVEN_VIDEO_MODE4_H
#define _LIBSEVEN_VIDEO_MODE4_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define MODE4_WIDTH  240
#define MODE4_HEIGHT 160

typedef       u16 Mode4Line[MODE4_WIDTH/2];
typedef Mode4Line Mode4Frame[MODE4_HEIGHT];

#define MODE4_FRAME     MEMDEFW(Mode4Frame, MEM_VRAM)
#define MODE4_FRAME2    MEMDEFW(Mode4Frame, MEM_VRAM + 0xA000)

#define M4PX(l, h) ((u16)((l) << 8 | (u8)(h)))

extern void* lcdInitMode4(void);

_LIBSEVEN_EXTERN_C_END

#endif
