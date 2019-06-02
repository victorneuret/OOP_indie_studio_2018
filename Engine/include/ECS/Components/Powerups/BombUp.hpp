/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombUp.hpp
*/

#pragma once

#include "ECS/Components/Powerups/APowerUp.hpp"

namespace Engine::Component::PowerUps {
    class BombUp;
}

class Engine::Component::PowerUps::BombUp : public Engine::ECS::Components::APowerUp {
public:
    BombUp();
};