cmake_minimum_required(VERSION 3.19)
project(exception C)

set(CMAKE_C_STANDARD 99)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

message(${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC
        ${PROJECT_SOURCE_DIR}/src/Fork/Fork.c
        ${PROJECT_SOURCE_DIR}/src/fork_util/user_fork.c
        ${PROJECT_SOURCE_DIR}/src/main.c src/Wait/Wait.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SRC})