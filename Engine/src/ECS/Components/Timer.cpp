/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.cpp
*/

#include "ECS/Components/Timer.hpp"
#include "ECS/Components/Chrono.hpp"

Engine::Component::Timer::Timer(const double &duration)
    : AComponent("Timer"), _duration(duration)
{
}

void Engine::Component::Timer::startCooldown()
{
    _timer.reset();
}

bool Engine::Component::Timer::isCooldownFinished(const std::function<void()> &func)
{
    if (_timer.getElapsedTime() >= _duration) {
        func();
        return true;
    }
    return false;
}