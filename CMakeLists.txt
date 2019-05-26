cmake_minimum_required(VERSION 3.11)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++")
endif (UNIX)

include_directories(
    Engine/include
    Game/include
    irrlicht
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
    Engine/include/Math/Vector/Vec2.hpp
    Engine/include/Math/Vector/Vec3.hpp
    Engine/include/Math/Vector/Rect.hpp
    Engine/include/Exception/AException.hpp
    Engine/include/Exception/Engine/EngineException.hpp
    Engine/include/Exception/Exception.hpp
    Engine/include/Exception/Engine/ECS/ECSException.hpp
    Engine/src/AException.cpp
    Engine/include/Exception/Permission/PermissionException.hpp
    Engine/include/Exception/NotImplementedException.hpp
    Engine/include/Exception/Memory/MemoryException.hpp
)

add_executable(
    bomberman
    Game/src/Main.cpp
)

target_link_libraries(bomberman engine Irrlicht sfml-audio)
