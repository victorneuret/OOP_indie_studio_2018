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
#include "Exception/Engine/EngineException.hpp"

std::unique_ptr<Engine::ECS::Manager> Engine::ECS::Manager::_instance{nullptr};
std::vector<std::shared_ptr<Engine::ECS::IEntity>> Engine::ECS::Manager::_entities{};
std::vector<std::shared_ptr<Engine::ECS::ISystem>> Engine::ECS::Manager::_systems{};
std::map<Engine::AScene::SceneType , Engine::AScene*> Engine::ECS::Manager::_scenes{};

Engine::ECS::Manager &Engine::ECS::Manager::getInstance()
{
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Manager>(new ECS::Manager());
        if (_instance == nullptr)
            throw MemoryException<Memory_Allocation_Failed>("Could not create engine instance.");
    }
    return *_instance;
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

Engine::AScene &Engine::ECS::Engine::getScene(const AScene::SceneType type)
{
    auto search = _scenes.find(type);

    if (search == _scenes.end())
        throw EngineException<Engine_ECS>{"Could not find the scene."};
    return *search->second;
}

void Engine::ECS::Engine::addScene(AScene &scene)
{
    _scenes[AScene::SceneType::GAME] = &scene;
}