/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Engine.cpp
*/

#include <algorithm>

#include "ECS/Engine.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

decltype(Engine::ECS::Engine::_entities) &Engine::ECS::Engine::getEntities() noexcept
{
    return _entities;
}

std::shared_ptr<Engine::ECS::IEntity> &Engine::ECS::Engine::getEntityByID(const size_t id)
{
    auto search = std::find_if(_entities.begin(), _entities.end(), [id](const std::shared_ptr<IEntity> &entity) {
        return entity->getID() == id;
    });

    if (search == _entities.end())
        throw ECSException<ECS_Entity>{"Entity " + std::to_string(id) + " not found"};
    return *search;
}

void Engine::ECS::Engine::addEntity(std::shared_ptr<IEntity> &entity)
{
    _entities.push_back(entity);
}

decltype(Engine::ECS::Engine::_systems) &Engine::ECS::Engine::getSystems() noexcept
{
    return _systems;
}

void Engine::ECS::Engine::addSystem(std::shared_ptr<ISystem> &system)
{
    _systems.push_back(system);
}
