/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.cpp
*/

#include "ECS/Components/Timer.hpp"
#include "ECS/Components/Chrono.hpp"

Engine::ECS::Component::Timer::Timer(const decltype(_duration) &duration, std::function<void()> &func)
    : AComponent{"Timer"}, _duration{duration}, _func{std::move(func)}
{
}

void Engine::ECS::Component::Timer::startCooldown()
{
    _timer.reset();
}

bool Engine::ECS::Component::Timer::execIfCooldownFinished()
{
    if (_timer.getElapsedTime() >= _duration) {
        _func();
        return true;
    }
    return false;
}

void Engine::ECS::Component::Timer::setDuration(const decltype(_duration) &duration)
{
    _duration = duration;
}

double Engine::ECS::Component::Timer::getDuration() const
{
    return _duration;
}
