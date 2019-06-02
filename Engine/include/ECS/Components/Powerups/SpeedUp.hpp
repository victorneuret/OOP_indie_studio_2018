/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.hpp
*/

#pragma once

#include "ECS/Components/Powerups/APowerUp.hpp"

namespace Engine::Component::PowerUps {
    class SpeedUp;
}

class Engine::Component::PowerUps::SpeedUp : public Engine::ECS::Components::APowerUp {
public:
    SpeedUp();

private:
};