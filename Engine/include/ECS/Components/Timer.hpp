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
private:

    Engine::ECS::Component::Chrono _timer{};
    double _duration{0};
    std::function<void()> _func;

public:
    Timer(const double &duration, std::function<void()> &func);

    void startCooldown();
    bool execIfCooldownFinished();

    void setDuration(const decltype(_duration) &duration);
    double getDuration() const;
};
