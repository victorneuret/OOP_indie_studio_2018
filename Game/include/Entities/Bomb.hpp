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
    size_t _range{1};
    size_t _playerID{0};

public:
    Bomb(const decltype(_playerID) &playerID, const decltype(_pos) &pos, const decltype(_range) &range);
    Bomb(const Bomb &) = delete;
    Bomb &operator=(const Bomb &) = delete;

    ~Bomb() override = default;

    static void _exploding(const Engine::Math::Vec3f &pos);
    void onExplode();
    const decltype(_pos) &getPos() const noexcept;
};
