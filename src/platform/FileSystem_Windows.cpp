#include "FileSystem_Windows.h"
#include "LogHandler.h"
#include <Windows.h>

namespace fileutils
{
     std::atomic<FileErrorCode> FileSystem_Platform::sErrorCode {FileErrorCode::Unknow};

     FileErrorCode FileSystem_Platform::getLastFileErrorCode()
     {
         return sErrorCode.load();
     }

     bool FileSystem_Platform::fileExists(const std::string& fileName)
     {
         DWORD fileAttributes = ::GetFileAttributesA(fileName.c_str());
         if (fileAttributes != INVALID_FILE_ATTRIBUTES && !(fileAttributes & FILE_ATTRIBUTE_DIRECTORY))
         {
             return true;
         }
         return false;
     }

    bool FileSystem_Platform::createFolder(const std::string& folderName)
    {
        if (CreateDirectoryA(folderName.c_str(), NULL) != 0) {
            return true;
        } else {
            sErrorCode.store(fromWindowErrorCode(GetLastError()));
        }
        return false;
    }

    bool FileSystem_Platform::deleteFolder(const std::string& folderName)
    {
        if (RemoveDirectoryA(folderName.c_str()) != 0) {
            return true;
        } else {
            sErrorCode.store(fromWindowErrorCode(GetLastError()));
        }
        return false;
    }

    bool FileSystem_Platform::folderExists(const std::string& folderName)
    {
         DWORD fileAttributes = ::GetFileAttributesA(folderName.c_str());
         if (fileAttributes != INVALID_FILE_ATTRIBUTES && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY))
         {
             return true;
         }
         return false;
    }

    std::string FileSystem_Platform::absolutePath(const std::string& path)
    {
        char absolutePath[MAX_PATH];
        if (GetFullPathNameA(path.c_str(), MAX_PATH, absolutePath, nullptr))
        {
            return absolutePath;
        }
        else
        {
            sErrorCode.store(fromWindowErrorCode(GetLastError()));
            return "";
        }
    }

     std::string FileSystem_Platform::getLastErrorString(int code)
     {
         return "";
     }

     FileErrorCode FileSystem_Platform::fromWindowErrorCode(int code)
     {
        const auto dwCode = static_cast<DWORD>(code);
        return code == ERROR_FILE_NOT_FOUND ? FileErrorCode::FileNotExist
             : code == ERROR_ALREADY_EXISTS ? FileErrorCode::FileAlreadyExist
             : code == ERROR_ACCESS_DENIED  ? FileErrorCode::NoAuthorization
             :                                FileErrorCode::Unknow;
     }
}