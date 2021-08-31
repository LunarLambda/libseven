#ifndef _LIBSEVEN_INPUT_H
#define _LIBSEVEN_INPUT_H

#include <seven_base.h>

enum Key
{
    KEY_A       = BIT(0),
    KEY_B       = BIT(1),
    KEY_SELECT  = BIT(2),
    KEY_START   = BIT(3),
    KEY_RIGHT   = BIT(4),
    KEY_LEFT    = BIT(5),
    KEY_UP      = BIT(6),
    KEY_DOWN    = BIT(7),
    KEY_R       = BIT(8),
    KEY_L       = BIT(9),
};

#define REG_KEYINPUT REG16(0x04000130)

enum KeycntFlags
{
    KC_IRQ_ENABLE       = BIT(14),
    KC_IRQ_AND          = BIT(15),
    KC_IRQ_OR           = !KC_IRQ_AND,
};

#define REG_KEYCNT REG16(0x04000132)

#endif /* !_LIBSEVEN_INPUT_H */
