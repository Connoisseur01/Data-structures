cmake_minimum_required(VERSION 3.12)

project(Data-structures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp" "src/util/*.hpp" "src/util/*.cpp")

set(TARGET_NAME
sdizo)

add_executable(${TARGET_NAME} ${SOURCES})