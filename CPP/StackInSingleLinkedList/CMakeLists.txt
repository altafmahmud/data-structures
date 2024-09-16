cmake_minimum_required(VERSION 3.10)

project(StackInSingleLinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_subdirectory(SingleLinkedList_lib)

add_executable(StackInSingleLinkedList src/main.cpp src/Stack.cpp)

target_include_directories(StackInSingleLinkedList PRIVATE include)

target_link_libraries(StackInSingleLinkedList SingleLinkedList)
