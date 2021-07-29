cmake_minimum_required(VERSION 3.10)

project(graph VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(./include)

set(HEADER_FILE ./include/graphs.hxx ./include/graphs.hpp)
# set(SOURCE_FILE source_sample.cpp)

add_executable(graph main.cpp ${HEADER_FILE} ${SOURCE_FILE})
