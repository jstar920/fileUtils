#pragma once
#include "Macro.h"
#include <string>
#include <functional>
namespace fileutils
{
    enum LogLevel {
        Debug,
        Info,
        Warning,
        Error
    };
    struct LogHandler
    {
        static void log(LogLevel level, const std::string& msg);

        static void setLogHandler(const std::function<void(int logLevel, const std::string& msg)>& logHandler);
    private:
        static const char* logLevelString(LogLevel level);
        static std::function<void(int logLevel, const std::string& msg)> sLog;
    };

    inline void LogDebug(const std::string& msg) {LogHandler::log(LogLevel::Debug, msg);}
    inline void LogInfo(const std::string& msg) {LogHandler::log(LogLevel::Info, msg);}
    inline void LogWarning(const std::string& msg) {LogHandler::log(LogLevel::Warning, msg);}
    inline void LogError(const std::string& msg) {LogHandler::log(LogLevel::Error, msg);}
};