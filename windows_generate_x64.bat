if exist windows_x64_output rmdir /Q /S windows_x64_output
mkdir windows_x64_output
cd windows_x64_output
cmake .. -G "Visual Studio 17 2022"
cd ..