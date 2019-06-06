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
#include "Exception/Engine/EngineException.hpp"

std::unique_ptr<Engine::ECS::Engine> Engine::ECS::Engine::_instance{nullptr};
std::vector<std::shared_ptr<Engine::ECS::ISystem>> Engine::ECS::Engine::_systems{};
std::vector<std::shared_ptr<Engine::Scene::AScene>> Engine::ECS::Engine::_scenes{};

Engine::ECS::Engine &Engine::ECS::Engine::getInstance()
{
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Engine>(new ECS::Engine());
        if (_instance == nullptr)
            throw MemoryException<Memory_Allocation_Failed>("Could not create engine instance.");
    }
    return *_instance;
}

decltype(Engine::ECS::Engine::_systems) &Engine::ECS::Engine::getSystems() noexcept
{
    return _systems;
}

std::shared_ptr<Engine::ECS::ISystem> &Engine::ECS::Engine::getSystemByID(const std::string &id)
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

std::shared_ptr<Engine::Scene::AScene> &Engine::ECS::Engine::getSceneByID(const std::string &id)
{
    for (auto &scene : _scenes)
        if (scene->getID() == id)
            return scene;
    throw ECSException<ECS_AScene>{"AScene " + id + " not found"};
}

void Engine::ECS::Engine::addScene(std::shared_ptr<Scene::AScene> &scene)
{
    _scenes.push_back(scene);
}

decltype(Engine::ECS::Engine::_scenes) &Engine::ECS::Engine::getScenes() noexcept
{
    return _scenes;
}

void Engine::ECS::Engine::sceneManager(double deltaTime)
{
    for (auto it = _scenes.end(); it >= _scenes.begin(); it++) {
        if ((*it)->isUpdateChild())
           (*it)->tick(deltaTime);
        if  ((*it)->isOpaque())
            break;
    }
}