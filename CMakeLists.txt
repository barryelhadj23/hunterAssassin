cmake_minimum_required(VERSION 3.26)
project(hunterassassin)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build)
set(SDL2_PATH "D:/SDL2-2.30.0/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(hunterassassin src/main.cpp)

target_link_libraries(hunterassassin ${SDL2_LIBRARY})