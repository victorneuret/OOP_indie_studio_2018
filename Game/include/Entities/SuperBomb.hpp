/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SuperBomb.hpp
*/

#pragma once

#include "Entities/APowerUp.hpp"

namespace Game::Entity {
    class SuperBomb;
}

class Game::Entity::SuperBomb : public Game::Entity::APowerUp {
public:
    SuperBomb(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/block/powerup.obj"));

    SuperBomb(const SuperBomb &) =  delete;
    SuperBomb &operator=(const SuperBomb &) = delete;

    ~SuperBomb() override = default;

    void applyEffect(std::shared_ptr<Game::Entity::Character> &player) override;
};