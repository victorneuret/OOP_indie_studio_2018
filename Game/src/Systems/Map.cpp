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
#include "Abstracts/AScene.hpp"

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

        if (_map.empty()) {
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

void Game::System::Map::_createBlock(const Engine::Math::Vec3f vec, const std::string &texture) noexcept
{
    std::shared_ptr<Engine::ECS::IEntity> block = std::make_shared<Game::Entity::Block>(vec, "assets/models/block/Column.obj");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->addTexture(texture);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->setScale(Engine::Math::Vec3{5.f, 2.f, 5.f});
    Engine::ECS::Engine::getInstance().addEntity(block);
}

void Game::System::Map::_createMap() noexcept
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));
    _createFirstSquare();
    _duplicateWidth();
    _duplicateHeight();

    for (const auto &elem : _map)
        std::cout << elem << std::endl;
    for (size_t i = 0; i < _map.size(); i++) {
        for (size_t j = 0; j <= MAP_WIDTH; j++) {
            if (_map[i][j] == '.')
                _createBlock(Engine::Math::Vec3f{INDEX_TO_POS(static_cast<float>(i)), 0, INDEX_TO_POS(static_cast<float>(j))}, "assets/models/block/Column.png");
            else if (_map[i][j] == '#')
                _createBlock(Engine::Math::Vec3f{INDEX_TO_POS(static_cast<float>(i)), 0, INDEX_TO_POS(static_cast<float>(j))}, "assets/models/block/unbreakable.png");
        }
    }
    std::shared_ptr<Engine::ECS::IEntity> block = std::make_shared<Game::Entity::Block>(Engine::Math::Vec3f{INDEX_TO_POS(MAP_WIDTH) / 2.f, -3, INDEX_TO_POS(MAP_WIDTH) / 2.f}, "assets/models/block/cube.obj");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->setScale(Engine::Math::Vec3{160.f, 6.f, 160.f});
    Engine::ECS::Engine::getInstance().addEntity(block);

    renderer->getSceneManager()->addCameraSceneNode(nullptr, irr::core::vector3df(INDEX_TO_POS(static_cast<float>(MAP_WIDTH / 2.f)), 125, INDEX_TO_POS(static_cast<float>(MAP_HEIGHT))), irr::core::vector3df(INDEX_TO_POS(static_cast<float>(MAP_WIDTH / 2.f)), 0, INDEX_TO_POS(static_cast<float>(MAP_WIDTH / 2.f))));
    renderer->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(INDEX_TO_POS(static_cast<float>(MAP_WIDTH / 2.f)), 20, 0), irr::video::SColorf(254.0f, 201.0f, 32.0f));
}

void Game::System::Map::update(double)
{
    if (_map.empty())
        _createMap();
}
