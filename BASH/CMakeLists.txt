cmake_minimum_required(VERSION 3.19)
project(BASH C)

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC
        ${PROJECT_SOURCE_DIR}/src/command/command.c
        ${PROJECT_SOURCE_DIR}/src/main.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SRC})