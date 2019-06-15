/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** FireUp.hpp
*/

#pragma once

#include "Entities/APowerUp.hpp"

namespace Game::Entity {
    class FireUp;
}

class Game::Entity::FireUp final : public Game::Entity::APowerUp {
public:
    FireUp(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/block/powerup.obj"));

    FireUp(const FireUp &) = delete;
    FireUp &operator=(const FireUp &) = delete;

    ~FireUp() override = default;

    void applyEffect(std::shared_ptr<Game::Entity::Character> &player) override;
};
