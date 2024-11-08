cmake_minimum_required(VERSION 3.10)

project(BinaryHeap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(BinaryHeap src/main.cpp src/BinaryHeap.cpp)

target_include_directories(BinaryHeap PRIVATE include)
