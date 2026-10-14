cmake_minimum_required(VERSION 4.1)
project(AlgAndDataSctructCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1_Iterators Labs/Lab1_Iterators.cpp)
add_executable(Lab1 Labs/Lab1.cpp)
add_executable(ListsWithIterators List/ListsWithIterators.cpp
        List/ListWithCircleOneDirection.cpp
        List/ListWithCircleWithIterator.cpp
        List/ListWithCircleOneDirectionWithIterator.cpp)
add_executable(ListsWithTwoDirections List/ListsWithTwoDirections.cpp)
add_executable(ListsWithOneDirection-NextOnly List/ListsWithOneDirection-NextOnly.cpp)
add_executable(ListsWithOneDirection-PrevOnly List/ListsWithOneDirection-PrevOnly.cpp)
add_executable(ListsWithOneDirection-NoEnd List/ListsWithOneDirection-NoEnd.cpp)
add_executable(ListWithCircle List/ListWithCircle.cpp)
add_executable(Iterator Iterators/Iterators.cpp
        Queue/Queue.cpp)
add_executable(ListWithCircleOneDirection List/ListWithCircleOneDirection.cpp)
add_executable(Lab2 Labs/Lab2.cpp)
add_executable(Stack Stack/stack.cpp)
add_executable(Queue Queue/Queue.cpp)
add_executable(Lab2_Iterators Labs/Lab2_Iterators.cpp)
add_executable(ListWithCircleWithIterator List/ListWithCircleWithIterator.cpp)
add_executable(ListWithCircleOneDirectionWithIterator List/ListWithCircleOneDirectionWithIterator.cpp)
