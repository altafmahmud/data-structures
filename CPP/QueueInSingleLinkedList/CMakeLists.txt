cmake_minimum_required(VERSION 3.10)

project(QueueInSingleLinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(SingleLinkedList_lib)

add_executable(QueueInSingleLinkedList src/main.cpp src/Queue.cpp)

target_include_directories(QueueInSingleLinkedList PRIVATE include)

target_link_libraries(QueueInSingleLinkedList SingleLinkedList)
