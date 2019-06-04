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
    Engine/src/Utils/Logger.cpp
    Engine/include/Utils/Logger.hpp
    Engine/include/ECS/Interfaces/IComponent.hpp
    Engine/include/ECS/Abstracts/AComponent.hpp
    Engine/src/ECS/Components/Chrono.cpp
    Engine/include/ECS/Components/Chrono.hpp
    Engine/include/ECS/Interfaces/IEntity.hpp
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
    Engine/include/ECS/Abstracts/Systems/AInput.hpp
    Engine/src/ECS/Systems/KeyboardInput.cpp
    Engine/include/ECS/Systems/MouseInput.hpp
    Engine/src/ECS/Systems/MouseInput.cpp
    Engine/include/ECS/Components/Timer.hpp
    Engine/src/ECS/Components/Timer.cpp
    Engine/include/Utils/TypeDisplayer.hpp
    Engine/include/GameApplication.hpp
    Engine/src/GameApplication.cpp
    Engine/include/ECS/Components/Renderer.hpp
    Engine/src/ECS/Components/Renderer.cpp
    Engine/include/ECS/Systems/Renderer.hpp
    Engine/src/ECS/Systems/Renderer.cpp
    Engine/include/ECS/Components/Timer.hpp
    Engine/src/ECS/Components/Timer.cpp
    Engine/include/Utils/Colors.hpp
    Engine/src/Utils/Color.cpp
    Engine/include/ECS/Components/Model3D.hpp
    Engine/src/ECS/Components/Model3D.cpp
    Engine/include/ECS/Components/Text.hpp
    Engine/src/ECS/Components/Text.cpp
    Engine/include/ECS/Components/Button.hpp
    Engine/src/ECS/Components/Button.cpp
    Engine/src/Utils/Random.cpp
    Engine/include/Utils/Random.hpp
)

add_executable(
    bomberman
    Game/src/Main.cpp
    Game/src/BombermanApplication.cpp
    Game/include/BombermanApplication.hpp
    Game/include/Entities/Block.hpp
    Game/src/Entities/Block.cpp
    Game/include/Entities/Player.hpp
    Game/src/Entities/Player.cpp
    Game/include/Entities/Text.hpp
    Game/src/Entities/Text.cpp
    Game/include/Entities/Button.hpp
    Game/src/Entities/Button.cpp
    Game/src/Systems/Map.cpp
    Game/include/Systems/Map.hpp
)

target_link_libraries(bomberman engine Irrlicht sfml-audio)
