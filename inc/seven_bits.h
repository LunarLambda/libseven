#ifndef _LIBSEVEN_BITS_H
#define _LIBSEVEN_BITS_H

#ifdef __cplusplus
extern "C" {
#endif

#define BIT(n)                  (1 << (n))
#define BITS(o, l)              ((BIT((l)) - 1) << (o))
#define BITFIELD(o, l, v)       (((v) & BITS(0, (l))) << (o))

#define BF_VALUE(name, value)           \
    BITFIELD((BF_##name##_OFFSET), (BF_##name##_LENGTH), (value))

#define BF_MASK(name)                   \
    BITS((BF_##name##_OFFSET), (BF_##name##_LENGTH), (value))

#define BF_INSERT(name, lhs, rhs)       \
    ((lhs) & ~BF_MASK(name) | BF_VALUE(name, (rhs))

#define BF_EXTRACT(name, lhs)           \
    ((lhs) >> (BF_##name##_OFFSET) & BITS(0, (BF_##name##_LEN)))

#define BF_CLEAR(name, lhs)             \
    BF_INSERT(name, (lhs), 0)

#define BF_AND(name, lhs, rhs) ((lhs) &  BF_VALUE(name, (rhs)))
#define BF_ORR(name, lhs, rhs) ((lhs) |  BF_VALUE(name, (rhs)))
#define BF_EOR(name, lhs, rhs) ((lhs) ^  BF_VALUE(name, (rhs)))
#define BF_BIC(name, lhs, rhs) ((lhs) & ~BF_VALUE(name, (rhs)))

#define BF_OR  BF_ORR
#define BF_XOR BF_EOR

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_BITS_H */
