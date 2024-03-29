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
#include "Abstracts/ASerializable.hpp"

namespace Game::Entity {
    class Character;
}

class Game::Entity::Character : public Engine::ECS::AEntity, public Engine::Abstracts::ASerializable {
protected:
    static uint8_t PLAYER_NB;
    std::string _playerID{std::to_string(PLAYER_NB % 4 + 1)};

    Engine::Math::Vec3f _pos{0, 0, 0};
    size_t _range{1};
    size_t _bombStock{1};
    size_t _maxBombStock{1};
    float _speed{0.0};
    bool _moving{false};
    bool _alive{true};
    float _time{0};
    bool _ghost{false};
    bool _inBlock{false};
    bool _superBomb{false};

    Engine::ECS::System::Audio::Sound _stepSound{};
    Engine::ECS::System::Audio::Sound _deathSound{};
    bool _isBombThere(const Engine::Math::Vec2i &pos);

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
    void powerUpAddBomb() noexcept;
    void setGhost(bool isGhost) noexcept;
    void setSuperBomb(bool value) noexcept;
    bool getSuperBomb() noexcept;
    const decltype(_playerID) &getPlayerId() const noexcept;

    void kill() noexcept;
    bool isAlive() const noexcept;
    const decltype(_pos) &getPosition() const;

    void pack(std::ostream &outStream) const override;
    void unpack(std::istream &inStream) override;

    void save() const;
    void load();
};
