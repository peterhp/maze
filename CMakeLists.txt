cmake_minimum_required(VERSION 2.8)

project(maze)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(HEADERS
    "util/algo.h"
    "maze/maze.h"
)

set(SOURCES
    "maze/maze.cpp"
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} "main.cpp")
