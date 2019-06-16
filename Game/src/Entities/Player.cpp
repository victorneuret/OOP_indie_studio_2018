/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include <memory>
#include <filesystem>

#include "Systems/Map.hpp"
#include "Entities/Player.hpp"
#include "Math/Vector/Vec3.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Components/Renderer.hpp"

decltype(Game::Entity::Player::PLAYER_NB) Game::Entity::Player::PLAYER_NB{0};

Game::Entity::Player::Player(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model)
    : Character{pos, texture, model}
{}

void Game::Entity::Player::load()
{
    const auto file = getFileHandler(".player_" + _playerID + ".save");

    if (file == nullptr || !file->is_open() || file->peek() == std::ifstream::traits_type::eof())
        return;

    file->seekp(0);
    unpack(*file);
}

void Game::Entity::Player::save() const
{
    const auto file = getFileHandler(".player_" + _playerID + ".save");

    Engine::Logger::getInstance().error("PLAYER");

    if (file != nullptr && file->is_open()) {
        std::filesystem::resize_file(".player_" + _playerID + ".save", 0);
        Engine::Logger::getInstance().error("Saved player");
        file->seekp(0);
        pack(*file);
        Engine::Logger::getInstance().error("Saved player OK");
    } else
        Engine::Logger::getInstance().error("Failed to save player");
}

void Game::Entity::Player::pack(std::ostream &outStream) const
{
    writeAny(outStream, _pos.x);
    writeAny(outStream, _pos.y);
    writeAny(outStream, _pos.z);
    writeAny(outStream, _range);
    writeAny(outStream, _bombStock);
    writeAny(outStream, _speed);
    writeAny(outStream, _alive);
    writeAny(outStream, _inBlock);
    writeAny(outStream, _ghost);
}

void Game::Entity::Player::unpack(std::istream &inStream)
{
    _pos.x = readAny<decltype(_pos.x)>(inStream);
    _pos.y = readAny<decltype(_pos.y)>(inStream);
    _pos.z = readAny<decltype(_pos.z)>(inStream);
    _range = readAny<decltype(_range)>(inStream);
    _bombStock = readAny<decltype(_bombStock)>(inStream);
    _speed = readAny<decltype(_speed)>(inStream);
    _inBlock = readAny<decltype(_inBlock)>(inStream);
    _ghost = readAny<decltype(_ghost)>(inStream);

    bool alive = readAny<decltype(_alive)>(inStream);

    if (!alive)
        kill();
}