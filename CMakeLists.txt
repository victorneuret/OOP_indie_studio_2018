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
    Engine/include/ECS/Manager.hpp
    Engine/src/ECS/Manager.cpp
    Engine/include/ECS/Abstracts/Systems/AInput.hpp
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
    Engine/src/Utils/Color.cpp
    Engine/include/ECS/Components/Model3D.hpp
    Engine/src/ECS/Components/Model3D.cpp
    Engine/include/ECS/Components/Text.hpp
    Engine/src/ECS/Components/Text.cpp
    Engine/include/ECS/Components/Button.hpp
    Engine/src/ECS/Components/Button.cpp
    Engine/src/Utils/Random.cpp
    Engine/include/Utils/Random.hpp
    Engine/include/ECS/Systems/EventHandler.hpp
    Engine/src/ECS/Systems/Audio.cpp
    Engine/include/ECS/Systems/Audio.hpp
    Engine/include/Exception/Engine/ECS/Systems/SoundException.hpp
    Engine/include/Abstracts/AScene.hpp
    Engine/src/Abstracts/AScene.cpp
    Engine/include/ECS/Entities/Button.hpp
    Engine/src/ECS/Entities/Button.cpp
    Engine/src/ECS/Abstract/ASystem.cpp
    Engine/src/ECS/Abstract/AEntity.cpp
    Engine/src/ECS/Abstract/AComponent.cpp
    Engine/include/ECS/Components/Image.hpp
    Engine/src/ECS/Components/Image.cpp
    Engine/include/ECS/Entities/Image.hpp
    Engine/src/ECS/Entities/Image.cpp
    Engine/include/ECS/Systems/Timer.hpp
    Engine/src/ECS/Systems/Timer.cpp
    Engine/src/Abstracts/AEntity.cpp
    Engine/include/ECS/Interfaces/Entities/IGuiElement.hpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Systems/AEvent.cpp
    Engine/src/ECS/Systems/EventHandler.cpp
    Engine/src/ECS/Systems/Event/ButtonEvent.cpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Systems/Input/AInput.cpp
    Engine/src/ECS/Systems/Input/KeyboardInput.cpp
    Engine/src/ECS/Systems/Input/MouseInput.cpp
    Engine/include/ECS/Systems/Input/JoystickInput.hpp
    Engine/src/ECS/Systems/Input/JoystickInput.cpp
    Engine/include/ECS/Systems/Input/KeyboardInput.hpp
    Engine/include/ECS/Systems/Input/MouseInput.hpp
    Engine/include/ECS/Components/Image.hpp
    Engine/src/ECS/Components/Image.cpp
    Engine/include/ECS/Entities/Image.hpp
    Engine/src/ECS/Entities/Image.cpp
    Engine/include/ECS/Interfaces/Entities/IGuiElement.hpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Systems/AEvent.cpp
    Engine/src/ECS/Systems/EventHandler.cpp
    Engine/src/ECS/Systems/Event/ButtonEvent.cpp
    Engine/src/ECS/Entities/IGuiElement.cpp
    Engine/src/ECS/Systems/Input/AInput.cpp
    Engine/src/ECS/Systems/Input/KeyboardInput.cpp
    Engine/src/ECS/Systems/Input/MouseInput.cpp
    Engine/include/ECS/Systems/Input/JoystickInput.hpp
    Engine/src/ECS/Systems/Input/JoystickInput.cpp
    Engine/include/ECS/Systems/Input/KeyboardInput.hpp
    Engine/include/ECS/Systems/Input/MouseInput.hpp
    Engine/src/ECS/Entities/Text.cpp
    Engine/include/ECS/Entities/Text.hpp
    Engine/include/ECS/Entities/Particle.hpp
    Engine/src/ECS/Entities/Particle.cpp
    Engine/include/ECS/Systems/Particle.hpp
    Engine/src/ECS/Systems/Particle.cpp
    Engine/include/ECS/Systems/InputHandler.hpp
    Engine/include/ECS/Interfaces/InputType.hpp
    Engine/include/irrlicht.hpp
    Engine/include/Effects/AudioVisualizer.hpp
    Engine/src/Effects/AudioVisualizer.cpp
    Engine/include/Abstracts/ASerializable.hpp
    Engine/src/Abstracts/ASerializable.cpp
    Engine/include/Exception/SerializationException.hpp
)

add_executable(
    bomberman
    Game/src/Main.cpp
    Game/src/BombermanApplication.cpp
    Game/include/BombermanApplication.hpp
    Game/src/Entities/Block.cpp
    Game/include/Entities/Player.hpp
    Game/include/Systems/Map.hpp
    Game/src/Entities/Player.cpp
    Game/src/Systems/Map.cpp
    Game/include/Scenes/MainMenu.hpp
    Game/src/Scenes/MainMenu.cpp
    Game/include/Scenes/GameScene.hpp
    Game/src/Scenes/GameScene.cpp
    Game/include/Entities/Bomb.hpp
    Game/src/Entities/Bomb.cpp
    Game/include/Entities/Character.hpp
    Game/src/Entities/Character.cpp
    Game/src/Systems/InputHandler.cpp
    Game/include/Systems/JoystickHandler.hpp
    Game/src/Systems/JoystickHandler.cpp
    Game/include/Systems/KeyboardHandler.hpp
    Game/src/Systems/KeyboardHandler.cpp
    Game/include/Scenes/PauseMenu.hpp
    Game/src/Scenes/PauseMenu.cpp
    Game/include/Assets.hpp
    Game/include/Entities/Powerups/BombUp.hpp
    Game/src/Entities/Powerups/BombUp.cpp
    Game/include/Entities/Powerups/FireUp.hpp
    Game/src/Entities/Powerups/FireUp.cpp
    Game/include/Entities/Powerups/SpeedUp.hpp
    Game/src/Entities/Powerups/SpeedUp.cpp
    Game/include/Entities/Powerups/APowerUp.hpp
    Game/src/Entities/Powerups/APowerUp.cpp
    Game/include/Entities/Powerups/GhostUp.hpp
    Game/src/Entities/Powerups/GhostUp.cpp
    Game/include/Entities/Powerups/SuperBomb.hpp
    Game/src/Entities/Powerups/SuperBomb.cpp
    Game/include/Components/BombTicker.hpp
    Game/src/Components/BombTicker.cpp
)
    Game/include/Scenes/OptionsMenu.hpp Game/src/Scenes/OptionsMenu.cpp)

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
