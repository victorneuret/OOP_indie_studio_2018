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
std::vector<std::shared_ptr<Engine::ECS::ISystem>> Engine::ECS::Manager::_systems{};
std::vector<std::shared_ptr<Engine::Abstracts::AScene>> Engine::ECS::Manager::_scenes{};

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
    _scenes.push_back(scene);
}

decltype(Engine::ECS::Manager::_scenes) &Engine::ECS::Manager::getScenes() noexcept
{
    return _scenes;
}

void Engine::ECS::Manager::sceneManager(double dt, std::shared_ptr<Engine::ECS::System::Renderer> &renderer)
{
    for (auto it = _scenes.rbegin(); it != _scenes.rend(); it++) {
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
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> updatedEntities{};

    for (auto it = _scenes.rbegin(); it != _scenes.rend(); it++) {
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
