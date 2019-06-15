/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PowerUp.hpp
*/

#pragma once

#include "ECS/Abstracts/ASystem.hpp"
#include "Entities/Character.hpp"

namespace Game::System {
    class PowerUp;
}

class Game::System::PowerUp : public Engine::ECS::ASystem {
public:
    PowerUp();

    void bombUp(Game::Entity::Character &player) const;
    void speedUp(Game::Entity::Character &player) const;
    void fireUp(Game::Entity::Character &player) const;
    void wallPass(Game::Entity::Character &player) const;

    void update(double dt) final;
};