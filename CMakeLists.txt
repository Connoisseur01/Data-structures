cmake_minimum_required(VERSION 3.0)

project(Data-structures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(SOURCES
src/*.cpp
)

set(TARGET_NAME
sdizo)

add_executable(${TARGET_NAME} ${SOURCES})