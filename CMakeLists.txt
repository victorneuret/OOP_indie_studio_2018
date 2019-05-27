cmake_minimum_required(VERSION 3.11)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++")

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        add_definitions(-DDEBUG=1)
    elseif (CMAKE_BUILD_TYPE MATCHES Release)
        add_definitions(-DRELEASE=1)
    endif ()
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
    Engine/include/ECS/Interfaces/IEntity.hpp
    Engine/include/ECS/Entities/AEntity.hpp
    Engine/include/Math/Vector/Vec2.hpp
    Engine/include/Math/Vector/Vec3.hpp
    Engine/include/Math/Rect.hpp
    Engine/include/Exception/AException.hpp
    Engine/include/Exception/Engine/EngineException.hpp
    Engine/include/Exception/Exception.hpp
    Engine/include/Exception/Engine/ECS/ECSException.hpp
    Engine/src/Exception/AException.cpp
    Engine/include/Exception/Permission/PermissionException.hpp
    Engine/include/Exception/NotImplementedException.hpp
    Engine/include/Exception/Memory/MemoryException.hpp
    Engine/include/ECS/Abstracts/ASystem.hpp
    Engine/include/ECS/Abstracts/AEntity.hpp
    Engine/include/ECS/Interfaces/ISystem.hpp
    Engine/include/ECS/Engine.hpp
    Engine/src/ECS/Engine.cpp
    Engine/include/ECS/Components/Timer.hpp
    Engine/src/ECS/Components/Timer.cpp
    Engine/include/Utils/TypeDisplayer.hpp
    Engine/include/GameApplication.hpp
    Engine/src/GameApplication.cpp
    Engine/src/IrrLichtContext.cpp
    Engine/include/IrrLichtContext.hpp
    Engine/include/ECS/Components/Renderer.hpp
    Engine/src/ECS/Components/Renderer.cpp
    Engine/include/ECS/Systems/Renderer.hpp
    Engine/src/ECS/Systems/Renderer.cpp
)

add_executable(
    bomberman
    Game/src/Main.cpp
    Game/src/BombermanApplication.cpp
    Game/include/BombermanApplication.hpp
)

target_link_libraries(bomberman engine Irrlicht sfml-audio)
