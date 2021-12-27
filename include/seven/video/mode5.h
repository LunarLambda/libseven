#ifndef _LIBSEVEN_VIDEO_MODE3_H
#define _LIBSEVEN_VIDEO_MODE3_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define MODE3_WIDTH  160
#define MODE3_HEIGHT 128

typedef       u16 Mode5Line[MODE5_WIDTH];
typedef Mode5Line Mode5Frame[MODE5_HEIGHT];

#define MODE5_FRAME     MEMDEFW(Mode5Frame, MEM_VRAM)
#define MODE5_FRAME2    MEMDEFW(Mode5Frame, MEM_VRAM + 0xA000)

extern void* lcdInitMode5(void);

_LIBSEVEN_EXTERN_C_END

#endif
