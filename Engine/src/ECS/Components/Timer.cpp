/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.cpp
*/

#include <iostream>

#include "ECS/Components/Timer.hpp"
#include "ECS/Components/Chrono.hpp"

Engine::Component::Timer::Timer()
    : AComponent("Timer")
{

}

void Engine::Component::Timer::cooldown(const double &duration)
{
    _duration = duration;
    _timer.reset();
}

bool Engine::Component::Timer::isCooldownFinish(const std::function<void()> &func)
{
    if (_timer.getElapsedTime() >= _duration) {
        func();
        return true;
    }
    return false;
}