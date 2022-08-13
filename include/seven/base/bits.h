/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_BASE_BITS_H
#define _LIBSEVEN_BASE_BITS_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define BIT(n)                          (1 << (n))
#define BITS(n)                         (BIT(n) - 1)

#define ROR(x, a)                       ((u32)(x) >> (a) | (u32)(x) << (32-(a)))
#define ROL(x, a)                       ((u32)(x) << (a) | (u32)(x) >> (32-(a)))

#define BIT_TRISTATE(val, m, p)         \
    (((val)>>(p)&1)-((val)>>(m)&1))

#define BITFIELD(name, value)           \
    (((value) & BITS((BF_##name##_LENGTH))) << (BF_##name##_OFFSET))

#define BF_AND(lhs, name, rhs)          ((lhs) &  BITFIELD(name, (rhs)))
#define BF_ORR(lhs, name, rhs)          ((lhs) |  BITFIELD(name, (rhs)))
#define BF_EOR(lhs, name, rhs)          ((lhs) ^  BITFIELD(name, (rhs)))
#define BF_BIC(lhs, name, rhs)          ((lhs) & ~BITFIELD(name, (rhs)))

#define BF_NOT(lhs, name)               ((lhs) ^ BF_MASK(name))
#define BF_NEG(lhs, name)               (BF_SET((lhs), name, -BF_GET((lhs), name)))

#define BF_ADD(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) + (rhs)))
#define BF_SUB(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) - (rhs)))
#define BF_MUL(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) * (rhs)))
#define BF_DIV(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) / (rhs)))
#define BF_MOD(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) % (rhs)))

#define BF_LSL(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) << (rhs)))
#define BF_LSR(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) >> (rhs)))
#define BF_ROL(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) << (rhs) | BF_GET((lhs), name) >> ((BF_##name##_LENGTH) - (rhs))))
#define BF_ROR(lhs, name, rhs)          (BF_SET((lhs), name, BF_GET((lhs), name) >> (rhs) | BF_GET((lhs), name) << ((BF_##name##_LENGTH) - (rhs))))

#define BF_MASK(name)                   \
    (BITS((BF_##name##_LENGTH)) << (BF_##name##_OFFSET))

#define BF_GET(lhs, name)               \
    ((lhs) >> ((BF_##name##_OFFSET)) & BITS((BF_##name##_LENGTH)))

#define BF_SET(lhs, name, rhs)          \
    (BF_ORR((lhs) & ~BF_MASK(name), name, (rhs)))

#define BF_ESET(lhs, name, enum)        \
    (((lhs) & ~BF_MASK(name)) | (name##_##enum))

#define BF_CMP(lhs, name, rhs)          \
    (BF_GET((lhs), name) == (rhs))

#define BF_ECMP(lhs, name, enum)        \
    (((lhs) & BF_MASK(name)) == name##_##enum)

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_BASE_BITS_H */
