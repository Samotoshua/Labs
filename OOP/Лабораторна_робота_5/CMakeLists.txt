cmake_minimum_required(VERSION 4.1)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/6.2.zip
)

FetchContent_MakeAvailable(raylib)

add_executable(lab4 main.cpp
        MyClass.cpp
        MyClass.h
        PolynomialGraph.cpp
        PolynomialGraph.h)

target_link_libraries(lab4 PRIVATE raylib)