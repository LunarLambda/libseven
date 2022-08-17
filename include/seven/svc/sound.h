/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SVC_SOUND_H
#define _LIBSEVEN_SVC_SOUND_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void svcSoundDriverMain(void);
extern void svcSoundDriverVSync(void);
extern void svcSoundChannelClear(void);
extern void svcSoundDriverVSyncOff(void);
extern void svcSoundDriverVSyncOn(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SVC_SOUND_H */
