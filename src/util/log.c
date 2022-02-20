/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <seven/util/log.h>

typedef bool LogInitFn(void);
typedef void LogOutputFn(u8, const char *);

static LogInitFn logInitNone;
static LogInitFn logInitMgba;
static LogInitFn logInitNocash;
static LogInitFn logInitVba;

static LogOutputFn logOutputNone;
static LogOutputFn logOutputMgba;
static LogOutputFn logOutputNocash;
static LogOutputFn logOutputVba;

static u8 LOG_MAX_LEVEL = LOG_OFF;

struct LogInterfaceDescriptor
{
    u32 id;
    LogInitFn *init;
    LogOutputFn *output;
    const char *name;
};

// List of log interfaces to try initializing
// VBA is not included due to the fact it has no dedicated presence check,
// And using it without checking can crash hardware and emulators using
// an official GBA BIOS ROM.
//
// FIXME: Would it be better to add flags to LogInterfaceDescriptor for "skip"?
static const enum LogInterface INTERFACE_SEARCH_ORDER[] =
{
    LOGIF_MGBA,
    LOGIF_NOCASH,

    // Sentinel
    LOGIF_NONE,
};

static const struct LogInterfaceDescriptor INTERFACES[] =
{
    { LOGIF_NONE,   logInitNone,   logOutputNone,   "None"               },
    { LOGIF_MGBA,   logInitMgba,   logOutputMgba,   "mGBA"               },
    { LOGIF_NOCASH, logInitNocash, logOutputNocash, "no$gba"             },
    { LOGIF_VBA,    logInitVba,    logOutputVba,    "Visual Boy Advance" },
};

static struct LogInterfaceDescriptor CUSTOM_INTERFACE =
{
    LOGIF_CUSTOM,
    NULL,
    NULL,
    "Custom",
};

static const struct LogInterfaceDescriptor *LOG_INTERFACE =
    &INTERFACES[LOGIF_NONE];

extern u8 logInit(void)
{
    const enum LogInterface *lid = INTERFACE_SEARCH_ORDER;
    const struct LogInterfaceDescriptor *lf;

    while ((lf = &INTERFACES[*lid]), !lf->init())
    {
        lid++;
    }

    LOG_INTERFACE = lf;

    return lf->id;
}

extern bool logInitInterface(u8 interface)
{
    if (interface >= (sizeof(INTERFACES) / sizeof(INTERFACES[0])))
    {
        return false;
    }

    const struct LogInterfaceDescriptor *l = &INTERFACES[interface];

    if (!l->init)
    {
        return false;
    }

    if (!l->init())
    {
        return false;
    }

    LOG_INTERFACE = l;

    return true;
}

extern void logInitCustom(LogCustomOutputFunction *f)
{
    CUSTOM_INTERFACE.output = f;
    LOG_INTERFACE = &CUSTOM_INTERFACE;
}

extern u8 logGetInterface(void)
{
    return LOG_INTERFACE->id;
}

extern const char* logGetInterfaceName(void)
{
    return LOG_INTERFACE->name;
}

extern u8 logGetMaxLevel(void)
{
    return LOG_MAX_LEVEL;
}

extern void logSetMaxLevel(u8 level)
{
    LOG_MAX_LEVEL = level;
}

extern void logOutput(u8 level, const char *message)
{
    // Prevent silliness with logOutput(LOG_OFF, "Message");
    if (!level || level > LOG_MAX_LEVEL)
    {
        return;
    }

    LOG_INTERFACE->output(level, message);
}

// Log interface implementations

static bool logInitNone(void)
{
    return true;
}

static void logOutputNone(u8 level, const char *message)
{
    (void)level;
    (void)message;
}

#define REG_MGBA_ENABLE         VOLADDR(0x04FFF780, u16)
#define REG_MGBA_FLAGS          VOLADDR(0x04FFF700, u16)
#define MGBA_LOG_OUT            ((char*)0x04FFF600)

static bool logInitMgba(void)
{
    REG_MGBA_ENABLE = 0xC0DE;

    return REG_MGBA_ENABLE == 0x1DEA;
}

static void logOutputMgba(u8 level, const char *message)
{
    for (int i = 0; message[i] && i < 256; i++)
    {
        MGBA_LOG_OUT[i] = message[i];
    }

    // FIXME: What if invalid level? Reject? Default to TRACE?
    REG_MGBA_FLAGS = (level - 1) | 0x100;
}

#define NOCASH_SIG              ((char*)0x04FFFA00)
#define REG_NOCASH_LOG          VOLADDR(0x04FFFA1C, u8)

static bool logInitNocash(void)
{
    for (int i = 0; i < 6; i++)
    {
        if ("no$gba"[i] != NOCASH_SIG[i])
        {
            return false;
        }
    }

    return true;
}

static void logOutputNocash(u8 level, const char *message)
{
    (void)level;

    while (*message)
    {
        REG_NOCASH_LOG = *message++;
    }

    REG_NOCASH_LOG = '\n';
}

static bool logInitVba(void)
{
    return true;
}

static void logOutputVba(u8 level, const char *message)
{
    (void)level;

    __asm__(
            "movs r0, %0\n"
            "svc  #255" :: "r" (message) : "r0"
           );

    __asm__(
            "movs r0, %0\n"
            "svc  #255" :: "r" ("\n") : "r0"
           );
}
