/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapSystem.cpp
*/

#include <algorithm>
#include <iostream>
#include <ECS/Components/Model3D.hpp>

#include "Systems/Map.hpp"
#include "Utils/Random.hpp"
#include "Entities/Block.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "Math/Vector/Vec3.hpp"

Game::System::Map::Map()
    : ASystem("Map")
{}

void Game::System::Map::_createFirstSquare() noexcept
{
    std::string str;
    uint64_t randomValue = 0;

    for (size_t i = 0; i < (MAP_HEIGHT + (MAP_HEIGHT % 2)) / 2; i++) {
        str.clear();

        for (size_t iChar = 0; iChar < (MAP_WIDTH + (MAP_WIDTH % 2)) / 2; iChar++) {
            randomValue = Random::getUnsigned(0, 5);
            switch (randomValue) {
                case 0: str.append("0"); break;
                case 1: str.append("#"); break;
                default: str.append(".");
            }
        }

        if (_map.size() == 0) {
            str[0] = '0';
            str[1] = '0';
        } else if (_map.size() == 1) {
            str[0] = '0';
        }

        _map.push_back(str);
    }
}

void Game::System::Map::_duplicateWidth() noexcept
{
    std::string copy;

    for (auto &elem : _map) {
        copy.clear();
        copy.append(elem);
        std::reverse(copy.begin(), copy.end());
        elem.append(copy);
    }
}

void Game::System::Map::_duplicateHeight() noexcept
{
    decltype(_map) mapCopy = _map;

    std::reverse(mapCopy.begin(), mapCopy.end());
    for (const auto &elem : mapCopy)
        _map.push_back(elem);
}


void Game::System::Map::_createMap() noexcept
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemsByID("Renderer"));
    _createFirstSquare();
    _duplicateWidth();
    _duplicateHeight();

    for (const auto &elem : _map)
        std::cout << elem << std::endl;
    for (float i = 0; i < _map.size(); i++) {
        for (float j = 0; j <= MAP_WIDTH; j++) {
            if (_map[i][j] == '.') {
                std::shared_ptr<Engine::ECS::IEntity> block = std::make_shared<Game::Entity::Block>(Engine::Math::Vec3f{i * 10, 0, (j * 10)}, "assets/models/block/WoodenCube/WoodenCube.obj");
                std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->addTexture("assets/models/block/WoodenCube/Textures/Wooden_Crate_Crate_Normal.png");
                std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->addTexture("assets/models/block/WoodenCube/Textures/Wooden_Crate_Crate_BaseColor.png");
                std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->addTexture("assets/models/block/WoodenCube/Textures/Wooden_Crate_Crate_Roughness.png");
                std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->addTexture("assets/models/block/WoodenCube/Textures/Wooden_Crate_Crate_Height.png");
                std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->setScale(Engine::Math::Vec3{2.f, 2.f, 2.f});
                Engine::ECS::Manager::getInstance().addEntity(block);
            }
        }
    }
}

void Game::System::Map::update(double)
{
    if (_map.empty())
        _createMap();
}
