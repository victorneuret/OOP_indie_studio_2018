cmake_minimum_required(VERSION 3.13)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++")

link_libraries(Irrlicht)

include_directories(
        ECS/include
        Components/include
)

add_executable(
        bomberman
        main.cpp
        ECS/include/Interfaces/IComponent.hpp
        ECS/include/Abstract/AComponent.hpp
        ECS/src/Abstract/AComponent.cpp
        Components/src/Chrono.cpp
        Components/src/Chrono.hpp
)
