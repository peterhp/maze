cmake_minimum_required(VERSION 2.8)

project(maze)

set(CMAKE_CXX_STANDARD 14)

set(HEADERS
    "maze/maze.h"
)

set(SOURCES
    "maze/maze.cpp"
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} "main.cpp")
