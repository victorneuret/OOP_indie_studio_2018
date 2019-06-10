/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.cpp
*/

#include "ECS/Components/Timer.hpp"
#include "ECS/Components/Chrono.hpp"

Engine::ECS::Component::Timer::Timer(const double &duration)
    : AComponent("Timer"), _duration(duration)
{
}

void Engine::ECS::Component::Timer::startCooldown()
{
    _timer.reset();
}

bool Engine::ECS::Component::Timer::execIfCooldownFinished(const std::function<void()> &func)
{
    if (_timer.getElapsedTime() >= _duration) {
        func();
        return true;
    }
    return false;
}