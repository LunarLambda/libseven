#ifndef _LIBSEVEN_ATTRIBUTES_H
#define _LIBSEVEN_ATTRIBUTES_H

#define ALIGN(n)        __attribute__((aligned(n)))
#define NORETURN        __attribute__((__noreturn__))
#define NOINLINE        __attribute__((noinline))
#define ARM_CODE        __attribute__((target("arm")))
#define THUMB_CODE      __attribute__((target("thumb")))

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

#endif /* !_LIBSEVEN_ATTRIBUTES_H */
