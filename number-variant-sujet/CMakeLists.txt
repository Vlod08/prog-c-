cmake_minimum_required(VERSION 3.8)

project(number-variant)

include_directories(include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT MSVC)
  add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wnull-dereference
    -Wold-style-cast
    -Wdouble-promotion
    -Wshadow)
endif()

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(number-variant ${SOURCES})
