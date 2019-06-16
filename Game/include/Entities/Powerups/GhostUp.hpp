/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GhostUp.hpp
*/

#pragma once

#include "Entities/Powerups/APowerUp.hpp"

namespace Game::Entity {
    class GhostUp;
}

class Game::Entity::GhostUp final : public Game::Entity::APowerUp {
public:
    GhostUp(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/block/powerup.obj"));

    GhostUp(const GhostUp &) = delete;
    GhostUp &operator=(const GhostUp &) = delete;

    ~GhostUp() override = default;

    void applyEffect(std::shared_ptr<Game::Entity::Character> &player) override;
};
