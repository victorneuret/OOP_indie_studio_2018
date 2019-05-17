/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AEntity.cpp
*/

#include <algorithm>

#include "ECS/Entities/AEntity.hpp"

void Engine::ECS::AEntity::addComponent(size_t id)
{
	_components.push_back(id);
}

void Engine::ECS::AEntity::removeComponent(size_t id)
{
	_components.erase(std::remove(_components.begin(), _components.end(), id), _components.end());
}

const decltype(Engine::ECS::AEntity::_components) &Engine::ECS::AEntity::components() const noexcept
{
    return _components;
}
