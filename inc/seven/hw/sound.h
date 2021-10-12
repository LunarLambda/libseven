#ifndef _LIBSEVEN_HW_SOUND_H
#define _LIBSEVEN_HW_SOUND_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void svcSoundDriverMain(void);
extern void svcSoundDriverVSync(void);
extern void svcSoundChannelClear(void);
extern void svcSoundDriverVSyncOff(void);
extern void svcSoundDriverVSyncOn(void);

// TODO: MusicPlayer* functions

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_HW_SOUND_H */
