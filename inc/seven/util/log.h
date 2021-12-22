#ifndef _LIBSEVEN_UTIL_LOG_H
#define _LIBSEVEN_UTIL_LOG_H

#include <seven/base.h>

_LIBSEVEN_EXTERN_C

enum LogLevel
{
    LOG_FATAL,
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
    LOG_TRACE,
    LOG_MAX,
};

// Supported log interfaces
enum LogInterface
{
    // No interface available
    LOGIF_NONE = 0,
    LOGIF_MGBA,
    LOGIF_NOCASH,
    LOGIF_VBA,
    LOGIF_CUSTOM = U8_MAX,
};

typedef void LogCustomOutputFunction(u8, const char *);

// Initializes the first available log interface, or returns LOGIF_NONE
extern u8 logInit(void);

// Tries to initialize the given log interface.
extern bool logInitInterface(u8 interface);

// Register a custom logging function.
extern void logInitCustom(LogCustomOutputFunction *f);

// Gets the current log interface.
extern u8 logGetInterface(void);

// Gets the name of the current log interface.
extern const char* logGetInterfaceName(void);

// Sets the current max log level.
extern void logSetMaxLevel(u8 level);

// Gets the current max log level.
extern u8 logGetMaxLevel(void);

// Output a message via the currently initialized log interface
extern void logOutput(u8 level, const char *message);

_LIBSEVEN_EXTERN_C_END

#endif /* _LIBSEVEN_UTIL_LOG_H */
