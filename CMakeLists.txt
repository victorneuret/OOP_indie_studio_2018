cmake_minimum_required(VERSION 3.13)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++")

link_libraries(Irrlicht)

include_directories(
  include
)

add_executable(
  bomberman
  src/main.cpp
  include/ECS/Interfaces/IComponent.hpp
  include/ECS/Abstracts/AComponent.hpp
  src/ECS/Components/Chrono.cpp
  include/ECS/Components/Chrono.hpp
  src/ECS/Abstracts/AComponent.cpp
  include/ECS/Interfaces/IEntity.hpp
  include/ECS/Entities/AEntity.hpp
)
