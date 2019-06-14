/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapSystem.cpp
*/

#include <algorithm>

#include "ECS/Components/Model3D.hpp"
#include "Systems/Map.hpp"
#include "Utils/Random.hpp"
#include "Entities/Block.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "Math/Vector/Vec3.hpp"
#include "Abstracts/AScene.hpp"
#include "Exception/AException.hpp"
#include "ECS/Manager.hpp"

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
        if (MAP_WIDTH % 2 == 1)
            copy.pop_back();
        std::reverse(copy.begin(), copy.end());
        elem.append(copy);
    }
}

void Game::System::Map::_duplicateHeight() noexcept
{
    decltype(_map) mapCopy = _map;

    if (MAP_HEIGHT % 2 == 1)
        mapCopy.pop_back();
    for (auto it = mapCopy.rbegin(); it != mapCopy.rend(); it++)
        _map.push_back(*it);
}

std::shared_ptr<Engine::ECS::IEntity> Game::System::Map::_createBlock(Engine::Math::Vec3f vec, const std::string &texture, bool breakable) noexcept
{
    std::shared_ptr<Engine::ECS::IEntity> block = std::make_shared<Game::Entity::Block>(breakable, vec);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->addTexture(texture);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->setScale(Engine::Math::Vec3{5.f, 2.f, 5.f});
    Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(block);
    return block;
}

void Game::System::Map::_createMap() noexcept
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));
    _createFirstSquare();
    _duplicateWidth();
    _duplicateHeight();

    for (size_t i = 0; i < _map.size(); i++) {
        std::vector<std::shared_ptr<Engine::ECS::IEntity>> blocks{};
        for (size_t j = 0; j <= MAP_WIDTH; j++) {
            if (_map[i][j] == '.')
                blocks.push_back(_createBlock(Engine::Math::Vec3f{INDEX_TO_POS(static_cast<float>(i)), 0, INDEX_TO_POS(static_cast<float>(j))}, "assets/models/block/Column.png", true));
            else if (_map[i][j] == '#')
                blocks.push_back(_createBlock(Engine::Math::Vec3f{INDEX_TO_POS(static_cast<float>(i)), 0, INDEX_TO_POS(static_cast<float>(j))}, "assets/models/block/unbreakable.png", false));
            else
                blocks.push_back(nullptr);
        }
        _blocks.push_back(blocks);
    }
    std::shared_ptr<Engine::ECS::IEntity> block = std::make_shared<Game::Entity::Block>(true, Engine::Math::Vec3f{INDEX_TO_POS(MAP_WIDTH - 1) / 2.f, -3, INDEX_TO_POS(MAP_HEIGHT - 1) / 2.f}, "assets/models/block/cube.obj");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(block->getComponentByID("Model3D"))->setScale(Engine::Math::Vec3{150.f, 6.f, 150.f});
    Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(block);

    _actualMap = _map;
}

void Game::System::Map::_placeCameraAndLight() noexcept
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));

    renderer->getSceneManager()->addCameraSceneNode(nullptr, irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 125, INDEX_TO_POS(static_cast<float>(MAP_HEIGHT - 1))), irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 0, INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f))));
    renderer->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 20, 0), irr::video::SColorf(254.0f, 201.0f, 32.0f));
}

void Game::System::Map::update(double)
{
    try {
        Engine::ECS::Manager::getInstance().getSceneByID("Game");
        if (_map.empty()) {
            _createMap();
            _placeCameraAndLight();
        }
    } catch (const ECSException<ECS_Scene> &e) {}

}

decltype(Game::System::Map::_actualMap) Game::System::Map::getActualMap() const noexcept
{
    return _actualMap;
}

void Game::System::Map::setActualMap(decltype(Game::System::Map::_actualMap) &map) noexcept
{
    _actualMap = map;
}

void Game::System::Map::removeBlock(const Engine::Math::Vec2i &pos)
{
    auto backupPos = pos - 1;
    if (_blocks[backupPos.x][backupPos.y] != nullptr) {
        if (!(std::dynamic_pointer_cast<Game::Entity::Block>(Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntityByID(_blocks[backupPos.x][backupPos.y]->getID()))->isBreakable()))
            return;
        std::dynamic_pointer_cast<Engine::ECS::Component::Model3D> (Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntityByID(_blocks[backupPos.x][backupPos.y]->getID())->getComponentByID("Model3D"))->getNode()->remove();
        Engine::ECS::Manager::getInstance().getSceneByID("Game")->removeEntityByID(_blocks[backupPos.x][backupPos.y]->getID());
    }
}
