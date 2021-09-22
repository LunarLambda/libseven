#include <seven_log.h>

typedef bool LogInitFn(void);
typedef void LogOutputFn(u8, const char *);

static LogInitFn logInitNone;
static LogInitFn logInitMgba;
static LogInitFn logInitNocash;

static LogOutputFn logOutputNone;
static LogOutputFn logOutputMgba;
static LogOutputFn logOutputNocash;

static u8 LOG_MAX_LEVEL = LOG_MAX;
static u8 LOG_INTERFACE = LOGIF_NONE;

static LogOutputFn *LOG_FUNCTION = logOutputNone;

struct LogInterfaceDescriptor
{
    u32 id;
    LogInitFn *init;
    LogOutputFn *output;
};

const static struct LogInterfaceDescriptor INTERFACES[] =
{
    {
        LOGIF_MGBA, logInitMgba, logOutputMgba
    },

    {
        LOGIF_NOCASH, logInitNocash, logOutputNocash
    },

    {
        LOGIF_NONE, logInitNone, logOutputNone
    },
};

extern u8 logInit(void)
{
    const struct LogInterfaceDescriptor *lid = INTERFACES;

    while (!lid->init())
    {
        lid++;
    }

    LOG_INTERFACE = lid->id;
    LOG_FUNCTION  = lid->output;

    return lid->id;
}

extern void logInitCustom(LogCustomOutputFunction *f)
{
    LOG_INTERFACE = LOGIF_CUSTOM;
    LOG_FUNCTION  = f;
}

extern u8 logGetInterface(void)
{
    return LOG_INTERFACE;
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
    if (level > LOG_MAX_LEVEL)
    {
        return;
    }

    LOG_FUNCTION(level, message);
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

#define REG_MGBA_ENABLE         REG16(0x04FFF780)
#define REG_MGBA_FLAGS          REG16(0x04FFF700)
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

    REG_MGBA_FLAGS = level | 0x100;
}

#define NOCASH_SIG              ((char*)0x04FFFA00)
#define REG_NOCASH_LOG          REG8(0x04FFFA1C)

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

