/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** Chrono.cpp
*/

#include "ECS/Components/Chrono.hpp"

Engine::Component::Chrono::Chrono(const size_t id)
    : Engine::ECS::AComponent(id), _start(std::chrono::system_clock::now())
{}

double Engine::Component::Chrono::getElapsedTime() const noexcept
{
    return (std::chrono::system_clock::now() - _start).count();
}

void Engine::Component::Chrono::reset() noexcept
{
    _start = std::chrono::system_clock::now();
}