cmake_minimum_required(VERSION 3.17)
project(c__First)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(c__First main.cpp Maniu.cpp test.c myutils.cpp)