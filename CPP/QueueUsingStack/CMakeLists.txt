cmake_minimum_required(VERSION 3.10)

project(QueueUsingStack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(QueueUsingStack src/main.cpp src/Queue.cpp)

target_include_directories(QueueUsingStack PRIVATE include)

