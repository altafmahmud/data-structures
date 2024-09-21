cmake_minimum_required(VERSION 3.10)

project(DoubleLinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(DoubleLinkedList src/main.cpp src/LinkedList.cpp)

target_include_directories(DoubleLinkedList PRIVATE include)
