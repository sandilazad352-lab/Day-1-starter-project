cmake_minimum_required(VERSION 3.20)
project(day1_native_hello C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(day1_hello
    src/main.c
)

target_include_directories(day1_hello PRIVATE include)

target_compile_options(day1_hello PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
