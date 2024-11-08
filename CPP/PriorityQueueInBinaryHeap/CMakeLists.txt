cmake_minimum_required(VERSION 3.10)

project(PriorityQueueInBinaryHeap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(BinaryHeap_lib)

add_executable(PriorityQueueInBinaryHeap src/main.cpp src/PriorityQueue.cpp)

target_include_directories(PriorityQueueInBinaryHeap PRIVATE include)

target_link_libraries(PriorityQueueInBinaryHeap BinaryHeap)
