/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.hpp
*/

#pragma once

#include <functional>

#include "ECS/Abstracts/AComponent.hpp"
#include "ECS/Components/Chrono.hpp"

namespace Engine::ECS::Component {
    class Timer;
}

class Engine::ECS::Component::Timer : public Engine::ECS::AComponent<Engine::ECS::Component::Timer> {
public:
    explicit Timer(const double &duration);

    void startCooldown();
    bool execIfCooldownFinished(const std::function<void()> &func);

private:

    Engine::ECS::Component::Chrono _timer{};
    double _duration{0};
};
