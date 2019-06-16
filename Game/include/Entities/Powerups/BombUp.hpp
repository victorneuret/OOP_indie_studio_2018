/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PowerUp.hpp
*/

#pragma once

#include "Entities/Powerups/APowerUp.hpp"

namespace Game::Entity {
    class BombUp;
}

class Game::Entity::BombUp final : public Game::Entity::APowerUp {
public:
    BombUp(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/block/powerup.obj"));

    BombUp(const BombUp &) = delete;
    BombUp &operator=(const BombUp &) = delete;

    ~BombUp() override = default;

    void applyEffect(std::shared_ptr<Game::Entity::Character> &player) override;
};
