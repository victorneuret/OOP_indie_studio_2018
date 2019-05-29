/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.hpp
*/

#pragma once

#include <chrono>
#include <functional>
#include <memory>

#include "ECS/Abstracts/AComponent.hpp"
#include "ECS/Components/Chrono.hpp"

namespace Engine::Component {
    class Timer;
}

class Engine::Component::Timer : public Engine::ECS::AComponent<Engine::Component::Timer> {
public:
    Timer();

    void cooldown(const double &duration);
    bool isCooldownFinish(const std::function<void()> &func);

private:

    Engine::Component::Chrono _timer{};
    double _duration{0};
};
