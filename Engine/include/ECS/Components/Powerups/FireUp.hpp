/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** FireUp.hpp
*/

#pragma once

#include "ECS/Components/Powerups/APowerUp.hpp"

namespace Engine::Component::PowerUps {
    class FireUp;
}

class Engine::Component::PowerUps::FireUp : public Engine::ECS::Components::APowerUp {
public:
    FireUp();
};