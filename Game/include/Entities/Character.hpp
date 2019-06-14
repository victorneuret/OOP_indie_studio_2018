/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.hpp
*/

#pragma once

#include "Math/Vector/Vec3.hpp"
#include "ECS/Abstracts/AEntity.hpp"

namespace Game::Entity {
    class Character;
}

class Game::Entity::Character : public Engine::ECS::AEntity {
protected:
    Engine::Math::Vec3f _pos{0, 0, 0};
    int _range{1};
    float _speed{0.0};

public:
    explicit Character(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model);
    Character(const Character &) = delete;
    Character &operator=(const Character &) = delete;

    ~Character() override = default;

    void placeBomb() const noexcept;
    void move(const Engine::Math::Vec2f &dir, double deltaTime) noexcept;
    const decltype(_speed) &getSpeed() const noexcept;
    void setSpeed(const decltype(_speed) &speed) noexcept;
};
