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

class Engine::ECS::Components::APowerUp : public Engine::ECS::AComponent<Engine::ECS::Components::APowerUp> {
public:
    APowerUp(const std::string &name, const double &duration);

    Engine::Component::Timer getCooldown() const;
    double getDuration() const;
private:
    Engine::Component::Timer _cooldown{};
    double _duration{0};
};