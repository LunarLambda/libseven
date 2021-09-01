#ifndef _LIBSEVEN_BITS_H
#define _LIBSEVEN_BITS_H

#ifdef __cplusplus
extern "C" {
#endif

#define BIT(n) (1 << (n))
#define BITS(s, l) ((BIT(l) - 1) << (s))
#define BIC(v, b) ((v) & ~(b))

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_BITS_H */
