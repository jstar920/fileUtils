#pragma once
#include "FileErrorCode.h"
#include <string>
#include <atomic>

namespace fileutils
{
    constexpr char SEPERATOR = '\\';
    class FileSystem_Platform
    {
    public:
        static FileErrorCode getLastFileErrorCode();
        static bool fileExists(const std::string& fileName);
        static bool createFolder(const std::string& folderName);
        static bool deleteFolder(const std::string& folderName);
        static bool folderExists(const std::string& folderName);
        static std::string absolutePath(const std::string& path);
    private:
        static FileErrorCode fromWindowErrorCode(int code);
        static std::string getLastErrorString(int code);
        static std::atomic<FileErrorCode> sErrorCode;
    };
}