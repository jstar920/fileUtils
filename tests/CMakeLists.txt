file (GLOB TESTS_HEADERS "*.h")
file (GLOB TESTS_SOURCES "*.cpp")

message(STATUS "header files:" ${TESTS_HEADERS})
message(STATUS "source files:" ${TESTS_SOURCES})

source_group("headers" FILES ${TESTS_HEADERS})
source_group("sources" FILES ${TESTS_SOURCES})

include_directories (.)

#add_library(tests SHARED ${TESTS_HEADERS} ${TESTS_SOURCES})
add_executable(fileutils_tests ${TESTS_HEADERS} ${TESTS_SOURCES})
target_link_libraries(fileutils_tests PUBLIC fileutils_static PUBLIC assure_static)

set_property(TARGET fileutils_tests PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR}/test)


#set_target_properties(assure PROPERTIES RUNTIME_OUTPUT_DIRECTORY %{PROJECT_BINARY_DIR}/bin)
