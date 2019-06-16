cmake_minimum_required(VERSION 3.11)
project(bomberman CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE off) # Turn on to debug cmake

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)
    set(CMAKE_MODULE_PATH .)

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        add_definitions(-DDEBUG=1)
    elseif (CMAKE_BUILD_TYPE MATCHES Release)
        add_definitions(-DRELEASE=1)
    endif ()
else ()
    set(CMAKE_MODULE_PATH ./irrlicht)
endif (UNIX)

include(${CMAKE_MODULE_PATH}/FindIrrlicht.cmake)

message(STATUS ${Irrlicht_INCLUDE_DIRS})
message(STATUS ${Irrlicht_LIBRARIES})

if (NOT ${Irrlicht_FOUND})
    error(SEND_ERROR "Can't find Irrlicht")
endif (NOT ${Irrlicht_FOUND})

include_directories(
    SFML
    ${Irrlicht_INCLUDE_DIRS}
    Engine/include
)

add_library(
    engine STATIC
    Engine/include/Abstracts/AScene.hpp
    Engine/include/Abstracts/ASerializable.hpp
    Engine/include/ECS/Abstracts/AComponent.hpp
    Engine/include/ECS/Abstracts/AEntity.hpp
    Engine/include/ECS/Abstracts/ASystem.hpp
    Engine/include/ECS/Abstracts/Systems/AInput.hpp
    Engine/include/ECS/Components/Button.hpp
    Engine/include/ECS/Components/Chrono.hpp
    Engine/include/ECS/Components/Image.hpp
    Engine/include/ECS/Components/Image.hpp
    Engine/include/ECS/Components/Model3D.hpp
    Engine/include/ECS/Components/Renderer.hpp
    Engine/include/ECS/Components/Text.hpp
    Engine/include/ECS/Components/Timer.hpp
    Engine/include/ECS/Components/Timer.hpp
    Engine/include/ECS/Entities/Button.hpp
    Engine/include/ECS/Entities/Image.hpp
    Engine/include/ECS/Entities/Image.hpp
    Engine/include/ECS/Entities/Particle.hpp
    Engine/include/ECS/Entities/Text.hpp
    Engine/include/ECS/Interfaces/Entities/IGuiElement.hpp
    Engine/include/ECS/Interfaces/Entities/IGuiElement.hpp
    Engine/include/ECS/Interfaces/IComponent.hpp
    Engine/include/ECS/Interfaces/IEntity.hpp
    Engine/include/ECS/Interfaces/InputType.hpp
    Engine/include/ECS/Interfaces/ISystem.hpp
    Engine/include/ECS/Manager.hpp
    Engine/include/ECS/Systems/ApplyPowerUp.hpp
    Engine/include/ECS/Systems/Audio.hpp
    Engine/include/ECS/Systems/EventHandler.hpp
    Engine/include/ECS/Systems/InputHandler.hpp
    Engine/include/ECS/Systems/Input/JoystickInput.hpp
    Engine/include/ECS/Systems/Input/JoystickInput.hpp
    Engine/include/ECS/Systems/Input/KeyboardInput.hpp
    Engine/include/ECS/Systems/Input/KeyboardInput.hpp
    Engine/include/ECS/Systems/Input/MouseInput.hpp
    Engine/include/ECS/Systems/Input/MouseInput.hpp
    Engine/include/ECS/Systems/Particle.hpp
    Engine/include/ECS/Systems/Renderer.hpp
    Engine/include/ECS/Systems/Timer.hpp
    Engine/include/Effects/AudioVisualizer.hpp
    Engine/include/Exception/AException.hpp
    Engine/include/Exception/Engine/ECS/ECSException.hpp
    Engine/include/Exception/Engine/ECS/Systems/SoundException.hpp
    Engine/include/Exception/Engine/EngineException.hpp
    Engine/include/Exception/Exception.hpp
    Engine/include/Exception/Memory/MemoryException.hpp
    Engine/include/Exception/NotImplementedException.hpp
    Engine/include/Exception/Permission/PermissionException.hpp
    Engine/include/Exception/SerializationException.hpp
    Engine/include/GameApplication.hpp
    Engine/include/irrlicht.hpp
    Engine/include/Math/Rect.hpp
    Engine/include/Math/Vector/Vec2.hpp
    Engine/include/Math/Vector/Vec3.hpp
    Engine/include/Utils/Logger.hpp
    Engine/include/Utils/Random.hpp
    Engine/include/Utils/TypeDisplayer.hpp
    Engine/src/Abstracts/AEntity.cpp
    Engine/src/Abstracts/AScene.cpp
    Engine/src/Abstracts/ASerializable.cpp
    Engine/src/ECS/Abstract/AComponent.cpp
    Engine/src/ECS/Abstract/AEntity.cpp
    Engine/src/ECS/Abstract/ASystem.cpp
    Engine/src/ECS/Components/Button.cpp
    Engine/src/ECS/Components/Chrono.cpp
    Engine/src/ECS/Components/Image.cpp
    Engine/src/ECS/Components/Image.cpp
    Engine/src/ECS/Components/Model3D.cpp
    Engine/src/ECS/Components/Renderer.cpp
    Engine/src/ECS/Components/Text.cpp
    Engine/src/ECS/Components/Timer.cpp
    Engine/src/ECS/Components/Timer.cpp
    Engine/src/ECS/Entities/Button.cpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Entities/Image.cpp
    Engine/src/ECS/Entities/Image.cpp
    Engine/src/ECS/Entities/Particle.cpp
    Engine/src/ECS/Entities/Text.cpp
    Engine/src/ECS/Manager.cpp
    Engine/src/ECS/Systems/AEvent.cpp
    Engine/src/ECS/Systems/AEvent.cpp
    Engine/src/ECS/Systems/ApplyPowerUp.cpp
    Engine/src/ECS/Systems/Audio.cpp
    Engine/src/ECS/Systems/Event/ButtonEvent.cpp
    Engine/src/ECS/Systems/Event/ButtonEvent.cpp
    Engine/src/ECS/Systems/EventHandler.cpp
    Engine/src/ECS/Systems/EventHandler.cpp
    Engine/src/ECS/Systems/Input/AInput.cpp
    Engine/src/ECS/Systems/Input/AInput.cpp
    Engine/src/ECS/Systems/Input/JoystickInput.cpp
    Engine/src/ECS/Systems/Input/JoystickInput.cpp
    Engine/src/ECS/Systems/Input/KeyboardInput.cpp
    Engine/src/ECS/Systems/Input/KeyboardInput.cpp
    Engine/src/ECS/Systems/Input/MouseInput.cpp
    Engine/src/ECS/Systems/Input/MouseInput.cpp
    Engine/src/ECS/Systems/Particle.cpp
    Engine/src/ECS/Systems/Renderer.cpp
    Engine/src/ECS/Systems/Timer.cpp
    Engine/src/Effects/AudioVisualizer.cpp
    Engine/src/Exception/AException.cpp
    Engine/src/GameApplication.cpp
    Engine/src/Utils/Color.cpp
    Engine/src/Utils/Logger.cpp
    Engine/src/Utils/Random.cpp
)

add_executable(
    bomberman
    Game/include/Assets.hpp
    Game/include/BombermanApplication.hpp
    Game/include/Entities/APowerUp.hpp
    Game/include/Entities/Bomb.hpp
    Game/include/Entities/BombUp.hpp
    Game/include/Entities/Character.hpp
    Game/include/Entities/FireUp.hpp
    Game/include/Entities/GhostUp.hpp
    Game/include/Entities/Player.hpp
    Game/include/Entities/SpeedUp.hpp
    Game/include/Scenes/GameScene.hpp
    Game/include/Scenes/MainMenu.hpp
    Game/include/Scenes/PauseMenu.hpp
    Game/include/Scenes/Selection.hpp
    Game/include/Systems/JoystickHandler.hpp
    Game/include/Systems/KeyboardHandler.hpp
    Game/include/Systems/Map.hpp
    Game/src/BombermanApplication.cpp
    Game/src/Entities/APowerUp.cpp
    Game/src/Entities/Block.cpp
    Game/src/Entities/Bomb.cpp
    Game/src/Entities/BombUp.cpp
    Game/src/Entities/Character.cpp
    Game/src/Entities/FireUp.cpp
    Game/src/Entities/GhostUp.cpp
    Game/src/Entities/Player.cpp
    Game/src/Entities/SpeedUp.cpp
    Game/src/Main.cpp
    Game/src/Scenes/GameScene.cpp
    Game/src/Scenes/MainMenu.cpp
    Game/src/Scenes/PauseMenu.cpp
    Game/src/Scenes/Selection.cpp
    Game/src/Systems/InputHandler.cpp
    Game/src/Systems/JoystickHandler.cpp
    Game/src/Systems/KeyboardHandler.cpp
    Game/src/Systems/Map.cpp
)

target_include_directories(bomberman PUBLIC Game/include)
target_link_libraries(bomberman engine ${Irrlicht_LIBRARIES} sfml-audio sfml-system)

if (UNIX)
    target_link_libraries(bomberman stdc++fs)
endif (UNIX)

add_executable(
    tests_run
    Engine/include/Math/Vector/Vec2.hpp
    Engine/include/Math/Vector/Vec3.hpp
    Tests/TestsVectors.cpp
    Tests/TestsRect.cpp
    Tests/Criterion.hpp
)

target_include_directories(tests_run PUBLIC Game/include Engine/include criterion)
target_link_libraries(tests_run sfml-audio sfml-system ${Irrlicht_LIBRARIES} criterion)

if (UNIX)
    target_compile_options(tests_run PUBLIC --coverage)
    target_link_options(tests_run PUBLIC --coverage)
    target_link_libraries(tests_run gcov)
endif (UNIX)
