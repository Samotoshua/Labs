cmake_minimum_required(VERSION 4.1)
project(AlgAndDataSctructCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1_Iterators Labs/Lab1_Iterators.cpp)
add_executable(Lab1 Labs/Lab1.cpp)
add_executable(ListsWithIterators Lists/ListsWithIterators.cpp
        Lists/ListWithCircleOneDirection.cpp)
add_executable(ListsWithTwoDirections Lists/ListsWithTwoDirections.cpp)
add_executable(ListsWithOneDirection-NextOnly Lists/ListsWithOneDirection-NextOnly.cpp)
add_executable(ListsWithOneDirection-PrevOnly Lists/ListsWithOneDirection-PrevOnly.cpp)
add_executable(ListsWithOneDirection-NoEnd Lists/ListsWithOneDirection-NoEnd.cpp)
add_executable(ListWithCircle Lists/ListWithCircle.cpp)
add_executable(Iterator Iterators/Iterators.cpp)
add_executable(ListWithCircleOneDirection Lists/ListWithCircleOneDirection.cpp)
