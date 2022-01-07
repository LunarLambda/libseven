/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_ATTRIBUTES_H
#define _LIBSEVEN_ATTRIBUTES_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define ALIGN(n)        __attribute__((aligned(n)))
#define NORETURN        __attribute__((__noreturn__))
#define NOINLINE        __attribute__((noinline))
#define ARM_CODE        __attribute__((target("arm")))
#define THUMB_CODE      __attribute__((target("thumb")))

#define SECTION(name) \
    __attribute__((section(name)))

#define IWRAM_FUNC(func) \
    __attribute__((section(".iwram." #func), noinline)) func
#define IWRAM_DATA(data) \
    __attribute__((section(".iwram." #data))) data
#define IWRAM_BSS(data) \
    __attribute__((section(".bss." #data))) data
#define EWRAM_FUNC(func) \
    __attribute__((section(".ewram." #func, noinline))) func
#define EWRAM_DATA(data) \
    __attribute__((section(".ewram." #data))) data
#define EWRAM_BSS(data) \
    __attribute__((section(".sbss." #data))) data

#define _LIBSEVEN_STR(s) #s
#define _LIBSEVEN_STR2(s) _LIBSEVEN_STR(s)

#define IWRAM_CODE \
    __attribute__((section(".iwram.text." _LIBSEVEN_STR2(__COUNTER__)), noinline))

#define EWRAM_CODE \
    __attribute__((section(".ewram.text." _LIBSEVEN_STR2(__COUNTER__)), noinline))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_ATTRIBUTES_H */
