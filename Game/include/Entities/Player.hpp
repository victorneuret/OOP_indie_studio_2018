/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.hpp
*/

#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Math/Vector/Vec3.hpp"
#include "Entities/Character.hpp"
#include "ECS/Abstracts/AEntity.hpp"

namespace Game::Entity {
    class Player;
}

class Game::Entity::Player final : public Game::Entity::Character {
protected:
    Engine::Math::Vec3d _pos{0, 0, 0};

public:
    explicit Player(const Engine::Math::Vec3f &pos = {0, 0, 0}, const std::string &model = std::string("assets/models/characters/Bomberman.MD3"));
    Player(const Player &) = delete;
    Player &operator=(const Player &) = delete;

    ~Player() override = default;
};
