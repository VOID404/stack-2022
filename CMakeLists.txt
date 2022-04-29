project(stos)
cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-fprofile-arcs -ftest-coverage)

include_directories("libs/")
include_directories("src/")

add_library(ut "libs/ut.hpp")
set_target_properties(ut PROPERTIES LINKER_LANGUAGE CXX)

add_library(stack "src/Stack.h")
set_target_properties(stack PROPERTIES LINKER_LANGUAGE CXX)

add_executable(test "src/Stack_test.cpp")
target_link_libraries(test stack ut -fprofile-arcs)
