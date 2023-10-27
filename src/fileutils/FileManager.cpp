#include "FileManager.h"

namespace fileutils
{
    std::atomic<FileErrorCode> FileManager::sErrorCode {FileErrorCode::Unknow};
    FileErrorCode FileManager::getLastFileErrorCode()
    {
        return sErrorCode.load();
    }

    bool FileManager::createFile(const std::string& fileName)
    {}
    bool FileManager::deleteFile(const std::string& fileName)
    {}
    bool FileManager::renameFile(const std::string& oldName, const std::string& newName)
    {}
    bool FileManager::fileExists(const std::string& fileName)
    {}
    bool FileManager::createFolder(const std::string& folderName)
    {}
    bool FileManager::deleteFolder(const std::string& folderName)
    {}
    bool FileManager::renameFolder(const std::string& oldName, const std::string& newName)
    {}
    bool FileManager::folderExists(const std::string& folderName)
    {}
    std::string fileName(const std::string& fullName)
    {}
    std::string folderName(const std::string& fullName)
    {}
    std::string joinPaths(const std::string& folder, const std::string& fileName)
    {}
}