#pragma once
#include <sstream>

#ifndef LOG_DEBUG
    #define LOG_DEBUG(msg) fileutils::LogDebug((std::stringstream() << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << " " << msg).str())
#endif

#ifndef LOG_INFO
    #define LOG_INFO(msg) fileutils::LogInfo((std::stringstream() << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << " " << msg).str())
#endif

#ifndef LOG_WARNING
    #define LOG_WARNING(msg) fileutils::LogWarning((std::stringstream() << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << " " << msg).str())
#endif

#ifndef LOG_ERROR
    #define LOG_ERROR(msg) fileutils::LogError((std::stringstream() << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << " " << msg).str())
#endif
