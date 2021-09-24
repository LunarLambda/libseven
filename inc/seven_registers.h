#ifndef _LIBSEVEN_REGISTER_H
#define _LIBSEVEN_REGISTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <seven_base.h>

#define REG8(addr)              (*(reg8*)(addr))
#define REG16(addr)             (*(reg16*)(addr))
#define REG32(addr)             (*(reg32*)(addr))

#define ROREG8(addr)            (*(const reg8*)(addr))
#define ROREG16(addr)           (*(const reg16*)(addr))
#define ROREG32(addr)           (*(const reg32*)(addr))

#define REG8_ARRAY(addr)        (&REG8(addr))
#define REG16_ARRAY(addr)       (&REG16(addr))
#define REG32_ARRAY(addr)       (&REG32(addr))

#define REG8_ARRAY_STRIDE(addr, stride, num) \
    (*(reg8*)((addr) + (stride) * (num)))

#define REG16_ARRAY_STRIDE(addr, stride, num) \
    (*(reg16*)((addr) + (stride) * (num)))

#define REG32_ARRAY_STRIDE(addr, stride, num) \
    (*(reg32*)((addr) + (stride) * (num)))

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_REGISTER_H */
