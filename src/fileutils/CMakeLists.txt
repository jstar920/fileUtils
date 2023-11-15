
file (GLOB FILEUTILS_HEADERS "*.h")
file (GLOB FILEUTILS_SOURCES "*.cpp")

message(STATUS "header files:" ${FILEUTILS_HEADERS})
message(STATUS "source files:" ${FILEUTILS_SOURCES})

source_group("headers" FILES ${FILEUTILS_HEADERS})
source_group("sources" FILES ${FILEUTILS_SOURCES})

include_directories (.)

add_library(fileutils SHARED ${FILEUTILS_HEADERS} ${FILEUTILS_SOURCES})
add_library(fileutils_static STATIC ${FILEUTILS_HEADERS} ${FILEUTILS_SOURCES})

set_property(TARGET fileutils PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
set_property(TARGET fileutils_static PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
target_include_directories(fileutils_static PUBLIC ".")
target_link_libraries(fileutils_static PUBLIC fileutils_common_static platform_static)
target_link_libraries(fileutils PUBLIC fileutils_common_static platform_static)

install (TARGETS fileutils
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)

