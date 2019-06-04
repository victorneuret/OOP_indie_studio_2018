/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Engine.cpp
*/

#include <algorithm>

#include "ECS/Engine.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

decltype(Engine::ECS::Engine::_systems) &Engine::ECS::Engine::getSystems() noexcept
{
    return _systems;
}

const decltype(Engine::ECS::Engine::_systems) &Engine::ECS::Engine::getSystems() const noexcept
{
    return _systems;
}

void Engine::ECS::Engine::addSystem(std::shared_ptr<ISystem> &system)
{
    _systems.push_back(system);
}
