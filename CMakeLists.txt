cmake_minimum_required(VERSION 3.11)
project(bomberman CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE off) # Turn on to debug cmake

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        add_definitions(-DDEBUG=1)
    elseif (CMAKE_BUILD_TYPE MATCHES Release)
        add_definitions(-DRELEASE=1)
    endif ()
endif (UNIX)

include_directories(
    SFML
    irrlicht
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
    Engine/include/ECS/Components/Player.hpp
    Engine/include/ECS/Systems/JoystickInput.hpp
    Engine/src/ECS/Systems/JoystickInput.cpp
    Engine/include/ECS/Systems/EventHandler.hpp
    Engine/src/ECS/Systems/Audio.cpp
    Engine/include/ECS/Systems/Audio.hpp
    Engine/include/Exception/Engine/ECS/Systems/SoundException.hpp
    Engine/include/ECS/Components/Slider.hpp
    Engine/src/ECS/Components/Slider.cpp
    Engine/include/ECS/Interfaces/Entities/IClickable.hpp
    Engine/include/ECS/Interfaces/Entities/IHoverable.hpp
    Engine/include/Abstracts/AScene.hpp
    Engine/src/Abstracts/AScene.cpp
    Engine/include/ECS/Entities/Text.hpp
    Engine/src/ECS/Entities/Text.cpp
    Engine/include/ECS/Entities/Button.hpp
    Engine/src/ECS/Entities/Button.cpp
    Engine/include/ECS/Entities/Slider.hpp
    Engine/src/ECS/Entities/Slider.cpp
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
)

target_include_directories(bomberman PUBLIC Game/include)
target_link_libraries(bomberman engine Irrlicht sfml-audio)

add_executable(
    tests_run
    Engine/include/Math/Vector/Vec2.hpp
    Engine/include/Math/Vector/Vec3.hpp
    Tests/TestsVectors.cpp
)

target_include_directories(tests_run PUBLIC Game/include Engine/include criterion)
target_link_libraries(tests_run sfml-audio Irrlicht criterion)

if (UNIX)
    target_compile_options(tests_run PUBLIC --coverage)
    target_link_options(tests_run PUBLIC --coverage)
    target_link_libraries(tests_run gcov)
endif (UNIX)
