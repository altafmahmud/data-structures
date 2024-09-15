cmake_minimum_required(VERSION 3.10)

project(StackInSingleLinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_library(SingleLinkedList SingleLinkedList.cpp)

add_executable(StackInSingleLinkedList main.cpp Stack.cpp)

target_link_libraries(StackInSingleLinkedList SingleLinkedList)
