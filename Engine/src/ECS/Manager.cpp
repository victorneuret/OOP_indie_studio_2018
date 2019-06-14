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
#include "Utils/Logger.hpp"

std::unique_ptr<Engine::ECS::Manager> Engine::ECS::Manager::_instance{nullptr};

Engine::ECS::Manager &Engine::ECS::Manager::getInstance()
{
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Manager>(new Manager);
        if (_instance == nullptr)
            throw MemoryException<Memory_Allocation_Failed>("Could not create engine instance.");
    }
    return *_instance;
}

decltype(Engine::ECS::Manager::_systems) &Engine::ECS::Manager::getSystems() noexcept
{
    return _systems;
}

std::shared_ptr<Engine::ECS::ISystem> &Engine::ECS::Manager::getSystemByID(const std::string &id)
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

std::shared_ptr<Engine::Abstracts::AScene> &Engine::ECS::Manager::getSceneByID(const std::string &id)
{
    for (auto &scene : _scenes)
        if (scene->getID() == id)
            return scene;
    throw ECSException<ECS_Scene>{"Scene " + id + " not found"};
}

void Engine::ECS::Manager::addScene(std::shared_ptr<Abstracts::AScene> &scene)
{
    if (scene->isOpaque() && !_scenes.empty()) {
        auto entities = getUpdatedEntities();
        for (auto &entity : entities)
            entity->hide();
    }
    if (!_scenes.empty())
        _scenes.back()->sceneHiding(scene.get());
    _scenes.push_back(scene);
}

void Engine::ECS::Manager::removeScene(std::shared_ptr<Engine::Abstracts::AScene> &scene)
{
    auto it = std::find(_scenes.begin(), _scenes.end(), scene);

    if (it != _scenes.end())
        _scenes.erase(it);
    else
        Logger::getInstance().warning("Scene " + scene->getID() + " already removed");
}

decltype(Engine::ECS::Manager::_scenes) &Engine::ECS::Manager::getScenes() noexcept
{
    return _scenes;
}

void Engine::ECS::Manager::sceneManager(double dt, std::shared_ptr<Engine::ECS::System::Renderer> &renderer)
{
    auto actualScenesStack = _scenes;

    for (auto it = actualScenesStack.rbegin(); it != actualScenesStack.rend(); it++) {
        if ((*it)->isUpdateChild())
           (*it)->tick(dt);
        for (auto &entity : (*it)->getEntities())
            renderer->draw(entity);
        if  ((*it)->isOpaque()) {
            break;
        }
    }
}

std::vector<std::shared_ptr<Engine::ECS::IEntity>> Engine::ECS::Manager::getUpdatedEntities()
{
    auto actualScenesStack = _scenes;
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> updatedEntities{};

    for (auto it = actualScenesStack.rbegin(); it != actualScenesStack.rend(); it++) {
        updatedEntities.insert(updatedEntities.end(), (*it)->getEntities().begin(), (*it)->getEntities().end());
        if (!(*it)->isUpdateChild() || (*it)->isOpaque())
            break;
    }
    return updatedEntities;
}

std::vector<std::shared_ptr<Engine::Abstracts::AScene>> Engine::ECS::Manager::getUpdatedScenes()
{
    std::vector<std::shared_ptr<Engine::Abstracts::AScene>> updatedScenes;

    for (auto it = _scenes.rbegin(); it != _scenes.rend(); it++) {
        updatedScenes.push_back(*it);
        if (!(*it)->isUpdateChild() || (*it)->isOpaque())
            break;
    }
    return updatedScenes;
}
