#pragma once

#include <string>

namespace fileutils
{
    enum class FileErrorCode
    {
        OK,
        Unknow,
        FileNotExist,
        FileAlreadyExist,
        DirectorNotExist,
        DirectorAlreadyExist,
        NoAuthorization,
        WrongFilePath
    };

    inline std::string errorInfo(FileErrorCode code) 
    {
        return code == FileErrorCode::OK                   ? "OK"
             : code == FileErrorCode::FileNotExist         ? "FileNotExist"
             : code == FileErrorCode::FileAlreadyExist     ? "FileAlreadyExist"
             : code == FileErrorCode::DirectorNotExist     ? "DirectorNotExist"
             : code == FileErrorCode::DirectorAlreadyExist ? "DirectorAlreadyExist"
             : code == FileErrorCode::NoAuthorization      ? "NoAuthorization"
             : code == FileErrorCode::WrongFilePath        ? "WrongFilePath"
             :                                               "Unknow";
    }

    inline FileErrorCode fromSystemCode(int code)
    {
        return code == 0      ? FileErrorCode::OK
             : code == EACCES ? FileErrorCode::NoAuthorization
             : code == ENOENT ? FileErrorCode::WrongFilePath
             :                  FileErrorCode::Unknow;
    }
}