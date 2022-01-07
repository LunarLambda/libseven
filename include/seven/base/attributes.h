/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_ATTRIBUTES_H
#define _LIBSEVEN_ATTRIBUTES_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define _LIBSEVEN_STR(s) #s
#define _LIBSEVEN_STR2(s) _LIBSEVEN_STR(s)

#define PACKED          __attribute__((packed))
#define ALIGN(n)        __attribute__((aligned(n)))
#define NORETURN        __attribute__((__noreturn__))
#define NOINLINE        __attribute__((noinline))
#define ARM_CODE        __attribute__((target("arm")))
#define THUMB_CODE      __attribute__((target("thumb")))

#define SECTION(name) \
    __attribute__((section(name)))

#define IWRAM_SECTION(suffix) SECTION(".iwram." suffix)
#define IWRAM_OVERLAY(number) SECTION(".iwram" #number)

#define IWRAM_CODE \
    __attribute__((section(".iwram.text." _LIBSEVEN_STR2(__COUNTER__)), noinline))

#define IWRAM_DATA \
    __attribute__((section(".iwram.data." _LIBSEVEN_STR2(__COUNTER__))))

#define IWRAM_BSS \
    __attribute__((section(".bss." _LIBSEVEN_STR2(__COUNTER__))))


#define EWRAM_SECTION(suffix) SECTION(".ewram." suffix)
#define EWRAM_OVERLAY(number) SECTION(".ewram" #number)

#define EWRAM_CODE \
    __attribute__((section(".ewram.text." _LIBSEVEN_STR2(__COUNTER__)), noinline))

#define EWRAM_DATA \
    __attribute__((section(".ewram.data." _LIBSEVEN_STR2(__COUNTER__))))

#define EWRAM_BSS \
    __attribute__((section(".sbss." _LIBSEVEN_STR2(__COUNTER__))))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_ATTRIBUTES_H */
