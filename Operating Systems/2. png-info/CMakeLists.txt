cmake_minimum_required(VERSION 3.17)
project(png_info C)

set(CMAKE_C_STANDARD 99)

add_executable(png_info main.c read.c)