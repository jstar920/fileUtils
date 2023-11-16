#include "FileSystem.h"
#include "assure.h"

namespace FileSystemTests
{
    using namespace fileutils;
    TEST_CASE("FileSystem_File", "FileSystem")
    {
        FileSystem::createFile("text1234.txt");
        ASSURE_TRUE(FileSystem::fileExists("text1234.txt"));
        FileSystem::renameFile("text1234.txt", "text4321.txt");
        ASSURE_FALSE(FileSystem::fileExists("text1234.txt"));
        ASSURE_TRUE(FileSystem::fileExists("text4321.txt"));
        FileSystem::deleteFile("text4321.txt");
        ASSURE_FALSE(FileSystem::fileExists("text4321.txt"));
    }

    TEST_CASE("FileSystem_Folder", "FileSystem")
    {
        FileSystem::createFolder("text1234");
        ASSURE_TRUE(FileSystem::folderExists("text1234"));
        FileSystem::renameFolder("text1234", "text4321");
        ASSURE_FALSE(FileSystem::folderExists("text1234"));
        ASSURE_TRUE(FileSystem::folderExists("text4321"));
        FileSystem::deleteFolder("text4321");
        ASSURE_FALSE(FileSystem::folderExists("text4321"));
    }

    TEST_CASE("FileSystem_FileName", "FileSystem")
    {
        const std::string path {"dir"};
        const std::string absolutePath = FileSystem::absolutePath(path);
        const std::string fileName {"file.txt"};
        const std::string jointPath = FileSystem::joinPaths(path, fileName);
        ASSURE_EQ(jointPath, std::string("dir") + FileSystem::SEPERATOR + "file.txt");

        const std::string uglyPath("././//dir/../\\\\dir///..///dir");
        const std::string cleanPath = FileSystem::absolutePath(uglyPath);
        ASSURE_EQ(cleanPath, absolutePath);
    }
}