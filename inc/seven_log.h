#ifndef _LIBSEVEN_LOG_H
#define _LIBSEVEN_LOG_H

#include <seven_base.h>

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
    LOGIF_CUSTOM,
};

typedef void LogCustomOutputFunction(u8, const char *);

// Initializes the first available log interface, or returns LOGIF_NONE
extern u8 logInit(void);

// Register a custom logging function.
extern void logInitCustom(LogCustomOutputFunction *f);

// Gets the current log interface.
extern u8 logGetInterface(void);

// Sets the current max log level.
extern void logSetMaxLevel(u8 level);

// Gets the current max log level.
extern u8 logGetMaxLevel(void);

// Output a message via the currently initialized log interface
extern void logOutput(u8 level, const char *message);

#endif /* _LIBSEVEN_LOG_H */
