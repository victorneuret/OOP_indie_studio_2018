/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Manager.cpp
*/

#include <algorithm>

#include "ECS/Manager.hpp"
#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Interfaces/ISystem.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"
#include "Exception/Memory/MemoryException.hpp"

std::unique_ptr<Engine::ECS::Manager> Engine::ECS::Manager::_instance{nullptr};
std::vector<std::shared_ptr<Engine::ECS::IEntity>> Engine::ECS::Manager::_entities{};
std::vector<std::shared_ptr<Engine::ECS::ISystem>> Engine::ECS::Manager::_systems{};

Engine::ECS::Manager &Engine::ECS::Manager::getInstance()
{
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Manager>(new ECS::Manager());
        if (_instance == nullptr)
            throw MemoryException<Memory_Allocation_Failed>("Could not create engine instance.");
    }
    return *_instance;
}

decltype(Engine::ECS::Manager::_entities) &Engine::ECS::Manager::getEntities() noexcept
{
    return _entities;
}

std::shared_ptr<Engine::ECS::IEntity> &Engine::ECS::Manager::getEntityByID(const size_t id)
{
    auto search = std::find_if(_entities.begin(), _entities.end(), [id](const std::shared_ptr<IEntity> &entity) {
        return entity->getID() == id;
    });

    if (search == _entities.end())
        throw ECSException<ECS_Entity>{"Entity " + std::to_string(id) + " not found"};
    return *search;
}

void Engine::ECS::Manager::addEntity(std::shared_ptr<IEntity> &entity)
{
    _entities.push_back(entity);
}

decltype(Engine::ECS::Manager::_systems) &Engine::ECS::Manager::getSystems() noexcept
{
    return _systems;
}

std::shared_ptr<Engine::ECS::ISystem> &Engine::ECS::Manager::getSystemsByID(const std::string &id)
{
    for (auto &elem : _systems)
        if (elem->getID() == id)
            return elem;
    throw ECSException<ECS_System>{"System " + id + " not found"};
}

void Engine::ECS::Manager::addSystem(std::shared_ptr<ISystem> &system)
{
    _systems.push_back(system);
}
