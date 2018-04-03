cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS-static)
set(SOURCE_FILES main.cpp Temperature.cc)
add_executable(untitled ${SOURCE_FILES})