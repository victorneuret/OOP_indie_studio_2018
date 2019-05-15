cmake_minimum_required(VERSION 3.13)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Weffc++")

add_executable(
        bomberman
        main.cpp
)

include_directories(
        "/usr/include/irrlicht/"
)

TARGET_LINK_LIBRARIES(
        bomberman
        "/usr/lib/libIrrlicht.so"
)
