cmake_minimum_required(VERSION 4.1)
project(lab6)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab6 main.cpp
        TInteger.cpp
        TInteger.h
        THeximal.cpp
        THeximal.h
        TBinary.cpp
        TBinary.h)
