/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Engine.cpp
*/

#include <algorithm>

#include "ECS/Engine.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"
#include "Exception/Memory/MemoryException.hpp"

std::unique_ptr<Engine::ECS::Engine> Engine::ECS::Engine::_instance{nullptr};
std::vector<std::shared_ptr<Engine::ECS::IEntity>> Engine::ECS::Engine::_entities{};
std::vector<std::shared_ptr<Engine::ECS::ISystem>> Engine::ECS::Engine::_systems{};

Engine::ECS::Engine &Engine::ECS::Engine::getInstance()
{
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Engine>(new ECS::Engine());
        if (_instance == nullptr)
            throw MemoryException<Memory_Allocation_Failed>("Could not create engine instance.");
    }
    return *_instance;
}

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

std::shared_ptr<Engine::ECS::ISystem> &Engine::ECS::Engine::getSystemsByID(const std::string &id)
{
    for (auto &elem : _systems)
        if (elem->getID() == id)
            return elem;
    throw ECSException<ECS_System>{"System " + id + " not found"};
}

void Engine::ECS::Engine::addSystem(std::shared_ptr<ISystem> &system)
{
    _systems.push_back(system);
}
