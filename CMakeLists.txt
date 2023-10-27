cmake_minimum_required (VERSION 2.6)

project(fileUtils)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

message("cxx Flags: " ${CMAKE_CXX_FLAGS})
message("CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR})
message("RUNTIME_OUTPUT_DIRECTORY: " ${RUNTIME_OUTPUT_DIRECTORY})


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if("${PRJECT_LIBRARIES_DIR}" STREQUAL "")
    set(PRJECT_LIBRARIES_DIR "libraries")
endif()

add_subdirectory(src)
add_subdirectory(tests)
