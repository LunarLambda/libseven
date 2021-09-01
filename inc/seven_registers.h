#ifndef _LIBSEVEN_REGISTER_H
#define _LIBSEVEN_REGISTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <seven_base.h>

#define REG8(addr)      (*(reg8*)(addr))
#define REG16(addr)     (*(reg16*)(addr))
#define REG32(addr)     (*(reg32*)(addr))

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_REGISTER_H */
