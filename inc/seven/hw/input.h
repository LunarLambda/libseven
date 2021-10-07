#ifndef _LIBSEVEN_INPUT_H
#define _LIBSEVEN_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <seven/base.h>

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

enum KeyGroups
{
    KEYS_DPAD_X         = KEY_LEFT      | KEY_RIGHT,
    KEYS_DPAD_Y         = KEY_UP        | KEY_DOWN,
    KEYS_DPAD           = KEYS_DPAD_X   | KEYS_DPAD_Y,
    KEYS_AB             = KEY_A         | KEY_B,
    KEYS_LR             = KEY_L         | KEY_R,
    KEYS_STARTSELECT    = KEY_START     | KEY_SELECT,
    KEYS_ANYBUTTON      = KEYS_AB       | KEYS_LR       | KEYS_STARTSELECT,
};

#define REG_KEYINPUT REG16(0x04000130)

enum KeyIRQFlags
{
    KEY_IRQ_ENABLE       = BIT(14),
    KEY_IRQ_PRESS_ALL    = BIT(15),
    KEY_IRQ_PRESS_ANY    = !KEY_IRQ_PRESS_ALL,
};

#define REG_KEYCNT REG16(0x04000132)

extern void inputPoll(void);

extern u16 inputKeysDown(void);
extern u16 inputKeysUp(void);
extern u16 inputKeysHeld(void);

extern void inputSetKeyIRQ(u16 keys, u16 op);

#ifdef __cplusplus
}
#endif

#endif /* !_LIBSEVEN_INPUT_H */
