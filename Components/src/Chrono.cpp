/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** Chrono.cpp
*/

#include "Chrono.hpp"

Engine::Chrono::Chrono(const size_t id)
    : Engine::ECS::AComponent(id), _start(std::chrono::system_clock::now())
{}

double Engine::Chrono::getElapsedTime() const noexcept
{
    return (std::chrono::system_clock::now() - _start).count();
}

void Engine::Chrono::reset() noexcept
{
    _start = std::chrono::system_clock::now();
}