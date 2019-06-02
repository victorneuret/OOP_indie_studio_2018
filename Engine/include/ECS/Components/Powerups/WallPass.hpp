/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** WallPass.hpp
*/

#pragma once

#include "ECS/Components/Powerups/APowerUp.hpp"

namespace Engine::Component::PowerUps {
    class WallPass;
}

class Engine::Component::PowerUps::WallPass : public Engine::ECS::Components::APowerUp {
public:
    WallPass();
};