/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_SVC_WAIT_H
#define _LIBSEVEN_SVC_WAIT_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

extern void svcHalt(void);
extern void svcStop(void);

extern void svcIntrWait(bool wait_next, u16 intr_flags);

enum IntrWaitExFlags
{
    IWE_WAIT_NEXT       = BIT(0),
    IWE_EXCLUSIVE       = BIT(1),
    IWE_INCLUSIVE       = !IWE_EXCLUSIVE,
};

extern void svcIntrWaitEx(u8 op, u16 intr_flags);

extern void svcVBlankIntrWait(void);

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_SVC_WAIT_H */
