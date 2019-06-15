/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** APowerUp.hpp
*/

#pragma once

#include "ECS/Abstracts/AEntity.hpp"
#include "Entities/Character.hpp"

namespace Game::Entity {
    class APowerUp;
}

class Game::Entity::APowerUp : public Engine::ECS::AEntity {
public:
    APowerUp();
    APowerUp(const APowerUp &) = delete;

    APowerUp &operator=(const APowerUp &) = delete;

    virtual void applyEffect(std::shared_ptr<Game::Entity::Character> &player) = 0;
};
