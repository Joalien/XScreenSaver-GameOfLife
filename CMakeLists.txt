cmake_minimum_required(VERSION 3.7)
project(XScreenSaver)
set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES GameOfLife.c)
add_executable(GameOfLife ${SOURCE_FILES})
set_target_properties(GameOfLife PROPERTIES COMPILE_FLAGS "-O3")

find_package(X11 REQUIRED)
target_link_libraries (GameOfLife X11)