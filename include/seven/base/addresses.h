/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_BASE_REGISTERS_H
#define _LIBSEVEN_BASE_REGISTERS_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define VOLADDR(addr, type)             (*(type volatile *)(addr))
#define VOLARRAY(addr, type, size)      (*(type volatile (*)[size])(addr))

#define VOLSERIES(addr, type, stride, index) \
    (*(type volatile *)((void*)(addr) + (stride) * (index)))

#define MEMADDR(addr, type)             (*(type *)(addr))
#define MEMARRAY(addr, type, size)      (*(type (*)[size])(addr))

#define MEMSERIES(addr, type, stride, index) \
    (*(type *)((void*)(addr) + (stride) * (index)))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_BASE_REGISTERS_H */
