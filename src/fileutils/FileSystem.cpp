#include "FileSystem.h"
#include "FileSystemPlatform.h"
#include "FileErrorCode.h"
#include "LogHandler.h"

#include <fstream>
#include <cstdio>
#include <cerrno>

namespace fileutils
{
    std::atomic<FileErrorCode> FileSystem::sErrorCode {FileErrorCode::Unknow};

    const char FileSystem::SEPERATOR { fileutils::SEPERATOR };
    FileErrorCode FileSystem::getLastFileErrorCode()
    {
        return sErrorCode.load();
    }

    bool FileSystem::createFile(const std::string& fileName)
    {
        std::ofstream outputFile(fileName);
        if (!outputFile.is_open())
        {
            sErrorCode.store(fromSystemCode(errno));
            LOG_WARNING("Can not create file:" << fileName <<  ", erroninfo:" << errorInfo(sErrorCode.load()));
            return false;
        }
        return true;
    }

    bool FileSystem::deleteFile(const std::string& fileName)
    {
        if (std::remove(fileName.c_str()))
        {
            sErrorCode.store(fromSystemCode(errno));
            LOG_WARNING("Can not delete file:" << fileName << ", erroninfo:" << errorInfo(sErrorCode.load()));
            return false;
        }
        return true;
    }

    bool FileSystem::renameFile(const std::string& oldName, const std::string& newName)
    {
        if (std::rename(oldName.c_str(), newName.c_str()))
        {
            sErrorCode.store(fromSystemCode(errno));
            LOG_WARNING("Can not rename file:" << oldName << ", erroninfo:" << errorInfo(sErrorCode.load()));
            return false;
        }
        return true;
    }

    bool FileSystem::fileExists(const std::string& fileName)
    {
        return FileSystem_Platform::fileExists(fileName);
    }

    bool FileSystem::createFolder(const std::string& folderName)
    {
        auto result =  FileSystem_Platform::createFolder(folderName);
        sErrorCode.store(FileSystem_Platform::getLastFileErrorCode());
        if (!result)
        {
             LOG_WARNING("Can not create folder:" << folderName << ", erroninfo:" << errorInfo(sErrorCode.load()));
        }
        return result;
    }

    bool FileSystem::deleteFolder(const std::string& folderName)
    {
        auto result =  FileSystem_Platform::deleteFolder(folderName);
        sErrorCode.store(FileSystem_Platform::getLastFileErrorCode());
        if (!result)
        {
             LOG_WARNING("Can not delete folder:" << folderName << ", erroninfo:" << errorInfo(sErrorCode.load()));
        }
        return result;
    }

    bool FileSystem::renameFolder(const std::string& oldName, const std::string& newName)
    {
        if (std::rename(oldName.c_str(), newName.c_str()))
        {
            sErrorCode.store(fromSystemCode(errno));
            LOG_WARNING("Can not rename folder:" << oldName << ", erroninfo:" << errorInfo(sErrorCode.load()));
            return false;
        }
        return true;
    }

    bool FileSystem::folderExists(const std::string& folderName)
    {
        return FileSystem_Platform::folderExists(folderName);
    }

    std::string FileSystem::fileName(const std::string& fullName)
    {
        size_t index = fullName.length() - 1;
        for (; index != 0; --index) 
        {
            if (fullName[index] == SEPERATOR) break;
        }
        return fullName.substr(index == 0 ? 0 : index + 1);
    }

    std::string FileSystem::folderName(const std::string& fullName)
    {
        size_t index = fullName.length() - 1;
        for (; index != 0; --index) 
        {
            if (fullName[index] == SEPERATOR) break;
        }
        return fullName.substr(0, index);
    }

    std::string FileSystem::joinPaths(const std::string& folder, const std::string& fileName)
    {
        return clearPath(folder + SEPERATOR + fileName);
    }

    std::string FileSystem::clearPath(const std::string& path)
    {
        std::string cleanPath;
        cleanPath.reserve(path.length());
        bool isSlash {false};
        for (const auto c : path)
        {
            if (c == '\\' || c == '/')
            {
                if (isSlash)
                {
                    continue;
                }
                else
                {
                    cleanPath.push_back(SEPERATOR);
                    isSlash = true;
                }
            }
            else
            {
                cleanPath.push_back(c);
                isSlash = false;
            }
        }
        return cleanPath;
    }

    std::string FileSystem::absolutePath(const std::string& path)
    {
        const auto abPath = FileSystem_Platform::absolutePath(path);
        sErrorCode.store(FileSystem_Platform::getLastFileErrorCode());
        if (abPath.empty())
        {
             LOG_WARNING("Can not get absolute path:" << path << ", erroninfo:" << errorInfo(sErrorCode.load()));
        }
        return abPath;
    }
}