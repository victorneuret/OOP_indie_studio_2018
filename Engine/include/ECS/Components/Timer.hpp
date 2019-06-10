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

namespace Engine::Component {
    class Timer;
}

class Engine::Component::Timer : public Engine::ECS::AComponent<Engine::Component::Timer> {
public:
    explicit Timer(const double &duration);

    void startCooldown();
    bool isCooldownFinished(const std::function<void()> &func);

private:

    Engine::ECS::Component::Chrono _timer{};
    double _duration{0};
};
