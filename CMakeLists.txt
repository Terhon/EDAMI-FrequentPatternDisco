cmake_minimum_required(VERSION 3.12)
project(spade)

set(CMAKE_CXX_STANDARD 14)

add_executable(spade src/main.cpp src/spade.cpp src/spade.hpp)