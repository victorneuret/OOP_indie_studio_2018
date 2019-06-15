/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.hpp
*/

#pragma once

#include "Math/Vector/Vec3.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Systems/Audio.hpp"

namespace Game::Entity {
    class Character;
}

class Game::Entity::Character : public Engine::ECS::AEntity {
protected:
    Engine::Math::Vec3f _pos{0, 0, 0};
    size_t _range{1};
    size_t _bombStock{1};
    float _speed{0.0};
    bool _moving{false};
    bool _alive{true};

    Engine::ECS::System::Audio::Sound _deathSound{};
public:
    Character(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model);
    Character(const Character &) = delete;
    Character &operator=(const Character &) = delete;

    ~Character() override = default;

    void placeBomb() noexcept;
    void move(const Engine::Math::Vec2f &dir, float deltaTime) noexcept;
    const decltype(_speed) &getSpeed() const noexcept;
    void setSpeed(const decltype(_speed) &speed) noexcept;
    void rangeIncrease() noexcept;
    void addBomb() noexcept;

    void kill() noexcept;
    bool isAlive() const noexcept;
    const decltype(_pos) &getPosition() const;
};
