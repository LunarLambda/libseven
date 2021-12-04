#ifndef _LIBSEVEN_REGISTERS_H
#define _LIBSEVEN_REGISTERS_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define MEMDEFR(type, addr) (*(const type *)(addr))
#define MEMDEFW(type, addr) (*(type *)(addr))

#define REG8(addr)              (*(reg8*)(addr))
#define REG16(addr)             (*(reg16*)(addr))
#define REG32(addr)             (*(reg32*)(addr))

#define ROREG8(addr)            (*(const reg8*)(addr))
#define ROREG16(addr)           (*(const reg16*)(addr))
#define ROREG32(addr)           (*(const reg32*)(addr))

#define REG8_ARRAY(addr)        (&REG8(addr))
#define REG16_ARRAY(addr)       (&REG16(addr))
#define REG32_ARRAY(addr)       (&REG32(addr))

#define ROREG8_ARRAY(addr)      (&ROREG8(addr))
#define ROREG16_ARRAY(addr)     (&ROREG16(addr))
#define ROREG32_ARRAY(addr)     (&ROREG32(addr))

#define REG8_ARRAY_STRIDE(addr, stride, num)    \
    (*(reg8*)((addr) + (stride) * (num)))

#define REG16_ARRAY_STRIDE(addr, stride, num)   \
    (*(reg16*)((addr) + (stride) * (num)))

#define REG32_ARRAY_STRIDE(addr, stride, num)   \
    (*(reg32*)((addr) + (stride) * (num)))

#define ROREG8_ARRAY_STRIDE(addr, stride, num)  \
    (*(const reg8*)((addr) + (stride) * (num)))

#define ROREG16_ARRAY_STRIDE(addr, stride, num) \
    (*(const reg16*)((addr) + (stride) * (num)))

#define ROREG32_ARRAY_STRIDE(addr, stride, num) \
    (*(const reg32*)((addr) + (stride) * (num)))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_REGISTERS_H */
