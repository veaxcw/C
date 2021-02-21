cmake_minimum_required(VERSION 2.8.4)
project(algorithim C)

set(CMAKE_C_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(hanoi)
include_directories(maze)
include_directories(sort)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(algorithim
        hanoi/hanoi.c
        hanoi/hanoi.h
        maze/common.h
        maze/maze.c
        maze/maze.h
        maze/stack.c
        maze/stack.h
        sort/sort.c
        sort/sort.h
        common/link_list.h common/link_list.c
        main.c)
