/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapSystem.cpp
*/

#include <ios>
#include <algorithm>
#include <filesystem>

#include <Entities/FireUp.hpp>
#include <Entities/SpeedUp.hpp>
#include <Entities/BombUp.hpp>
#include "ECS/Components/Model3D.hpp"
#include "Systems/Map.hpp"
#include "Utils/Random.hpp"
#include "Entities/Block.hpp"
#include "Entities/FireUp.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "Scenes/Selection.hpp"
#include "Math/Vector/Vec3.hpp"
#include "Abstracts/AScene.hpp"
#include "Exception/AException.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Particle.hpp"

Game::System::Map::Map()
    : ASystem{"Map"}
{}

void Game::System::Map::_createFirstSquare() noexcept
{
    std::string str;
    uint64_t randomValue = 0;

    for (size_t i = 0; i < (MAP_HEIGHT + (MAP_HEIGHT % 2)) / 2; i++) {
        str.clear();

        for (size_t iChar = 0; iChar < (MAP_WIDTH + (MAP_WIDTH % 2)) / 2; iChar++) {
            if (iChar == 0 || i == 0) {
                str.append(".");
                continue;
            }
            randomValue = Random::getUnsigned(0, 3);
            switch (randomValue) {
                case 0: str.append("0"); break;
                case 1: str.append("#"); break;
                default: str.append("."); break;
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

void Game::System::Map::_initMap() noexcept
{
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

    _placeCameraAndLight();
}

void Game::System::Map::_createMap() noexcept
{
    _createFirstSquare();
    _duplicateWidth();
    _duplicateHeight();

    _initMap();
}

void Game::System::Map::_placeCameraAndLight() noexcept
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));
    renderer->getSceneManager()->setActiveCamera(renderer->getSceneManager()->addCameraSceneNode(nullptr,
        irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 125, INDEX_TO_POS(static_cast<float>(MAP_HEIGHT - 1))),
        irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 0,INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)))));
    renderer->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 20, 0), irr::video::SColorf(254.0f, 201.0f, 32.0f));

    std::shared_ptr<Engine::Abstracts::AScene> selection = std::make_shared<Scene::Selection>();
    Engine::ECS::Manager::getInstance().pushScene(selection);
}

void  Game::System::Map::loadMap()
{
    const auto file = getFileHandler(SAVE_FILE);

    if (file == nullptr || !file->is_open() || file->peek() == std::ifstream::traits_type::eof()) {
        Engine::Logger::getInstance().error("Failed to load map from save");
        return;
    }

    file->seekp(0);
    unpack(*file);
}

void Game::System::Map::saveMap() const
{
    const auto file = getFileHandler(SAVE_FILE);

    if (file != nullptr && file->is_open()) {
        std::filesystem::resize_file(SAVE_FILE, 0);
        file->seekp(0);
        pack(*file);
    } else
        Engine::Logger::getInstance().error("Failed to write save map");
}

void Game::System::Map::update(double)
{
    try {
        Engine::ECS::Manager::getInstance().getSceneByID("Game");
        if (_map.empty())
            _createMap();
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
        std::dynamic_pointer_cast<Engine::ECS::System::Particle>(Engine::ECS::Manager::getInstance().getSystemByID("Particle"))->
            createParticles(15, Engine::Math::Vec2f{0.5, 1},
                Engine::Math::Vec3f{static_cast<float>(INDEX_TO_POS(backupPos.x)), 0, static_cast<float>(INDEX_TO_POS(backupPos.y))},
                Engine::Math::Vec3f{static_cast<float>(INDEX_TO_POS(backupPos.x)), 4, static_cast<float>(INDEX_TO_POS(backupPos.y))},
                0.5, "Game");
        _randomPowerup(pos);
        std::dynamic_pointer_cast<Engine::ECS::Component::Model3D> (Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntityByID(_blocks[backupPos.x][backupPos.y]->getID())->getComponentByID("Model3D"))->getNode()->remove();
        Engine::ECS::Manager::getInstance().getSceneByID("Game")->removeEntityByID(_blocks[backupPos.x][backupPos.y]->getID());
        _blocks[backupPos.x][backupPos.y] = nullptr;
        _actualMap[backupPos.x][backupPos.y] = '0';
        saveMap();
    }
}

decltype(Game::System::Map::_blocks) &Game::System::Map::getBlocks() noexcept
{
    return _blocks;
}

void Game::System::Map::pack(std::ostream &outStream) const
{
    writeAny(outStream, MAP_HEIGHT);
    writeAny(outStream, MAP_WIDTH);

    for (const auto &line : _actualMap)
        writeString(outStream, line);
}

void Game::System::Map::unpack(std::istream &inStream)
{
    const auto height = readAny<uint8_t>(inStream);
    const auto width = readAny<uint8_t>(inStream);

    _map.clear();

    for (uint8_t i = 0; i < height; i++) {
        const auto line = readString(inStream);

        if (line.size() != width)
            throw SerializationException("Save is invalid");
        _map.push_back(line);
    }

    _initMap();

void Game::System::Map::_randomPowerup(const Engine::Math::Vec2i &pos) noexcept
{
//    auto result = Random::getSigned(0, 100);
    auto result = Random::getSigned(0, 20);

    if (result <= 20) {
        if (result <= 5) {
            std::shared_ptr<Engine::ECS::IEntity> newFireUp = std::make_shared<Game::Entity::FireUp>(Engine::Math::Vec3f{static_cast<float>(INDEX_TO_POS(pos.x - 1)), 5, static_cast<float>(INDEX_TO_POS(pos.y - 1))});
            Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(newFireUp);
        }
        else if (result > 5 && result <= 10) {
            std::shared_ptr<Engine::ECS::IEntity> newSpeedUp = std::make_shared<Game::Entity::SpeedUp>(Engine::Math::Vec3f{static_cast<float>(INDEX_TO_POS(pos.x - 1)), 5, static_cast<float>(INDEX_TO_POS(pos.y - 1))});
            Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(newSpeedUp);
        }
        else if (result > 10 && result <= 15) {
            std::shared_ptr<Engine::ECS::IEntity> newBombUp = std::make_shared<Game::Entity::BombUp>(Engine::Math::Vec3f{static_cast<float>(INDEX_TO_POS(pos.x - 1)), 5, static_cast<float>(INDEX_TO_POS(pos.y - 1))});
            Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(newBombUp);
        }
    }
}
