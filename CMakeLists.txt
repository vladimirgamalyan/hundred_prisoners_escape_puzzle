cmake_minimum_required(VERSION 3.13)
enable_testing()
project(hundred_prisoners_escape_puzzle)
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)
add_executable(hundred_prisoners_escape_puzzle ${SOURCE_FILES})
add_test(NAME test COMMAND hundred_prisoners_escape_puzzle)
