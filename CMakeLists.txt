cmake_minimum_required(VERSION 3.11)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++")

include_directories(
    Engine/include
    Game/include
)

add_library(
    engine STATIC
    Engine/src/Logger.cpp
    Engine/include/Logger.hpp
    Engine/include/ECS/Interfaces/IComponent.hpp
    Engine/include/ECS/Abstracts/AComponent.hpp
    Engine/src/ECS/Components/Chrono.cpp
    Engine/include/ECS/Components/Chrono.hpp
    Engine/src/ECS/Abstracts/AComponent.cpp
    Engine/include/ECS/Interfaces/IEntity.hpp
    Engine/include/ECS/Entities/AEntity.hpp
    Engine/src/ECS/Abstracts/AEntity.cpp
)

add_executable(
    bomberman
    Game/src/Main.cpp
)

target_link_libraries(bomberman engine Irrlicht sfml-audio)
