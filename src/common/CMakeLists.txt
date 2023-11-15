
file (GLOB FileUTILS_COMMON_HEADERS "*.h")
file (GLOB FileUTILS_COMMON_SOURCES "*.cpp")

message(STATUS "header files:" ${FileUTILS_COMMON_HEADERS})
message(STATUS "source files:" ${FileUTILS_COMMON_SOURCES})

source_group("headers" FILES ${FileUTILS_COMMON_HEADERS})
source_group("sources" FILES ${FileUTILS_COMMON_SOURCES})

include_directories (.)

add_library(fileutils_common SHARED ${FileUTILS_COMMON_HEADERS} ${FileUTILS_COMMON_SOURCES})
add_library(fileutils_common_static STATIC ${FileUTILS_COMMON_HEADERS} ${FileUTILS_COMMON_SOURCES})

set_property(TARGET fileutils_common PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
set_property(TARGET fileutils_common_static PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
target_include_directories(fileutils_common_static PUBLIC ".")
target_link_libraries(fileutils_common_static PUBLIC timeutils_static)
target_link_libraries(fileutils_common PUBLIC timeutils_static)

install (TARGETS fileutils_common
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)

