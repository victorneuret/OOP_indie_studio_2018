/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Bomb.hpp
*/

#pragma once

#include "Math/Vector/Vec2.hpp"
#include "ECS/Abstracts/AEntity.hpp"

namespace Game::Entity {
    class Bomb;
}

class Game::Entity::Bomb final : public Engine::ECS::AEntity {
protected:
    Engine::Math::Vec2i _pos{0, 0};
    int _range{10};

public:
    explicit Bomb(const decltype(_pos) &pos);
    Bomb(const Bomb &) = delete;
    Bomb &operator=(const Bomb &) = delete;

    ~Bomb() override = default;

    void onExplode();
    const decltype(_pos) &getPos() const noexcept;
};
