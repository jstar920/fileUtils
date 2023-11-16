#pragma once
#include <atomic>
#include <string>

namespace fileutils
{
    enum class FileErrorCode;
    class FileSystem
    {
    public:
        static FileErrorCode getLastFileErrorCode();
        static bool createFile(const std::string& fileName);
        static bool deleteFile(const std::string& fileName);
        static bool renameFile(const std::string& oldName, const std::string& newName);
        static bool fileExists(const std::string& fileName);
        static bool createFolder(const std::string& folderName);
        static bool deleteFolder(const std::string& folderName);
        static bool renameFolder(const std::string& oldName, const std::string& newName);
        static bool folderExists(const std::string& folderName);
        static std::string fileName(const std::string& fullName);
        static std::string folderName(const std::string& fullName);
        static std::string joinPaths(const std::string& folder, const std::string& fileName);
        static std::string clearPath(const std::string& path);
        static std::string absolutePath(const std::string& path);

    private:
        static std::atomic<FileErrorCode> sErrorCode;
    public:
        const static char SEPERATOR;
    };
}