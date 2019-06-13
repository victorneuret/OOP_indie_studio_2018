/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Power-up.hpp
*/

#pragma once

#include <functional>

#include "ECS/Abstracts/AComponent.hpp"
#include "ECS/Components/Timer.hpp"

namespace Engine::ECS::Components {
    class APowerUp;
}

class Engine::ECS::Components::APowerUp : public Engine::ECS::AComponent {
public:
    APowerUp(const std::string &name, const double &duration);

    //Engine::ECS::Component::Timer getCooldown() const;
    double getDuration() const;
private:
    //Engine::ECS::Component::Timer _cooldown{5};
    double _duration{0};
};