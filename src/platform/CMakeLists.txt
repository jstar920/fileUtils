
file (GLOB PLATFORM_WINDOWS_HEADERS
    FileSystem_Windows.h
)
file (GLOB PLATFORM_WINDOWS_SOURCES
    FileSystem_Windows.cpp
)

file (GLOB PLATFORM_LINUX_HEADERS
    FileSystem_Linux.h
)
file (GLOB PLATFORM_LINUX_SOURCES
    FileSystem_Linux.cpp
)


if(WIN32)
    message("Compiling for Windows")
    set(PLATFORM_HEADERS ${PLATFORM_WINDOWS_HEADERS})
    set(PLATFORM_SOURCES ${PLATFORM_WINDOWS_SOURCES})
elseif(UNIX)
    set(PLATFORM_HEADERS ${PLATFORM_LINUX_HEADERS})
    set(PLATFORM_SOURCES ${PLATFORM_LINUX_SOURCES})
else()
    message(FATAL_ERROR "Unsupported operating system")
endif()


message(STATUS "header files:" ${PLATFORM_HEADERS})
message(STATUS "source files:" ${PLATFORM_SOURCES})

source_group("headers" FILES ${PLATFORM_HEADERS})
source_group("sources" FILES ${PLATFORM_SOURCES})

include_directories (.)

add_library(platform SHARED ${PLATFORM_HEADERS} ${PLATFORM_SOURCES})
add_library(platform_static STATIC ${PLATFORM_HEADERS} ${PLATFORM_SOURCES})

set_property(TARGET platform PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
set_property(TARGET platform_static PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
target_include_directories(platform_static PUBLIC ".")
target_link_libraries(platform_static PUBLIC fileutils_common_static)
target_link_libraries(platform PUBLIC fileutils_common_static)

install (TARGETS platform
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)

