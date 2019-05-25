/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Chrono.cpp
*/

#include <chrono>

#include "ECS/Components/Chrono.hpp"

double Engine::Component::Chrono::getElapsedTime() noexcept
{
    auto now = std::chrono::system_clock::now();
    _elapsedTime = now - _start;
    return _elapsedTime.count();
//    return (std::chrono::system_clock::now() - _start).count();
}

void Engine::Component::Chrono::reset() noexcept
{
    _start = std::chrono::system_clock::now();
}
