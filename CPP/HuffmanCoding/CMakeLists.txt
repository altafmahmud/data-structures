cmake_minimum_required(VERSION 3.10)

project(HuffmanCoding LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(HuffmanCoding src/main.cpp src/HuffmanCoding.cpp)

target_include_directories(HuffmanCoding PRIVATE include)