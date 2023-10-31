#pragma once

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

    inline FileErrorCode fromSystemCode(int code)
    {
        return code == 0      ? FileErrorCode::OK
             : code == EACCES ? FileErrorCode::NoAuthorization
             : code == ENOENT ? FileErrorCode::WrongFilePath
             :                  FileErrorCode::Unknow;
    }
}