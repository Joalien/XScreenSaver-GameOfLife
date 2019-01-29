cmake_minimum_required(VERSION 3.7)
project(XScreenSaver)
set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES GameOfLife.c)
add_executable(GameOfLife ${SOURCE_FILES})

find_package(X11 REQUIRED)
target_link_libraries (GameOfLife X11)