cmake_minimum_required(VERSION 3.26)
project(hunterassassin)

set(CMAKE_CXX_STANDARD 23)

set(NOYAUTEST_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(HUNTERASSASSIN_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build)
set(SDL2_PATH "D:/SDL2-2.30.0/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(hunterassassin src/mainProject.cpp
        src/config_Variable.h
        src/Player.cpp
        src/Player.h
        src/Rect.h
        src/Game.cpp
        src/Game.h)

add_executable(NoyauTest src/main.cpp
                         src/Player.cpp
                         src/Player.h)

set_target_properties(NoyauTest PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${NOYAUTEST_OUTPUT_PATH}
)

set_target_properties(hunterassassin PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${HUNTERASSASSIN_OUTPUT_PATH}
)

target_link_libraries(hunterassassin ${SDL2_LIBRARY})