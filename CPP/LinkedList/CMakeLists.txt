cmake_minimum_required(VERSION 3.10)

project(LinkedListProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_executable(LinkedListProject main.cpp LinkedList.cpp)
