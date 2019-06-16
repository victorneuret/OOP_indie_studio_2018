/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PowerUp.hpp
*/

#pragma once

#include "Entities/Powerups/APowerUp.hpp"

namespace Game::Entity {
    class SpeedUp;
}

class Game::Entity::SpeedUp final : public Game::Entity::APowerUp {
public:
    SpeedUp(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/block/powerup.obj"));

    SpeedUp(const SpeedUp &) = delete;
    SpeedUp &operator=(const SpeedUp &) = delete;

    ~SpeedUp() override = default;

    void applyEffect(std::shared_ptr<Game::Entity::Character> &player) override;
};
