#include "LogHandler.h"
#include "WallClock.h"
#include <iostream>

namespace fileutils
{
    std::function<void(int logLevel, const std::string& msg)> LogHandler::sLog;
    void LogHandler::log(LogLevel level, const std::string& msg)
    {
        if (sLog)
        {
            sLog(level, msg);
        }
        else
        {
            std::cout << timeutils::WallClock::getCurrentTimeUTCAsLogTimestamp() << " " << logLevelString(level) << " " << msg << std::endl;
        }
    }

    void LogHandler::setLogHandler(const std::function<void(int logLevel, const std::string& msg)>& logHandler)
    {
        sLog = logHandler;
    }

    const char* LogHandler::logLevelString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::Debug: return "[Debug]";
        case LogLevel::Info: return "[Info]";
        case LogLevel::Warning: return "[Warning]";
        case LogLevel::Error: return "[Error]";
        }

        return "[Debug]";
    }
}
