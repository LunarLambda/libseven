/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef _LIBSEVEN_BITS_H
#define _LIBSEVEN_BITS_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

#define BIT(n)                  (1 << (n))
#define BITS(n)                 (BIT(n) - 1)

#define BIT_TRISTATE(val, m, p) \
    (((val)>>(p)&1)-((val)>>(m)&1))

#define BITFIELD(name, value)   \
    (((value) & BITS((BF_##name##_LENGTH))) << (BF_##name##_OFFSET))

#define BF_AND(name, lhs, rhs)  ((lhs) &  BITFIELD(name, (rhs)))
#define BF_ORR(name, lhs, rhs)  ((lhs) |  BITFIELD(name, (rhs)))
#define BF_EOR(name, lhs, rhs)  ((lhs) ^  BITFIELD(name, (rhs)))
#define BF_BIC(name, lhs, rhs)  ((lhs) & ~BITFIELD(name, (rhs)))

#define BF_MASK(name)           \
    (BITS((BF_##name##_LENGTH)) << (BF_##name##OFFSET))

#define BF_GET(name, lhs)       \
    ((lhs) >> ((BF_##name##_OFFSET)) & BITS(BF_##name##_LENGTH))

#define BF_SET(name, lhs, rhs)  \
    (BF_ORR(name, BF_BIC(name, (lhs), BF_MASK(name)), (rhs)))

_LIBSEVEN_EXTERN_C_END

#endif /* !_LIBSEVEN_BITS_H */
