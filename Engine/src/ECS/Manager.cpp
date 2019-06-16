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
#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Image.hpp"

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

void Engine::ECS::Manager::pushScene(std::shared_ptr<Abstracts::AScene> &scene)
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

void Engine::ECS::Manager::popScene()
{
    if (_scenes.empty()) {
        Logger::getInstance().warning("No scenes are showing.");
        return;
    }

    auto top = _scenes.end() - 1;

    if (_scenes.size() != 1) {
        auto parent = top - 1;
        (*parent)->sceneShowing();
        for (auto &entity : (*parent)->getEntities()) {
            entity->show();
        }
    }

    _scenes.erase(top);
}

decltype(Engine::ECS::Manager::_scenes) &Engine::ECS::Manager::getScenes() noexcept
{
    return _scenes;
}

void Engine::ECS::Manager::sceneManager(double dt, std::shared_ptr<Engine::ECS::System::Renderer> &renderer)
{
    auto actualScenesStack = _scenes;
    auto search = std::find_if(actualScenesStack.rbegin(), actualScenesStack.rend(), [](const std::shared_ptr<Engine::Abstracts::AScene> &scene) {
        return scene->isOpaque();
    });

    for (auto it = std::find(actualScenesStack.begin(), actualScenesStack.end(), *search); it != actualScenesStack.end(); it++) {
        (*it)->tick(dt);
        for (auto &entity : (*it)->getEntities())
            renderer->draw(entity);
    }
}

std::vector<std::shared_ptr<Engine::ECS::IEntity>> Engine::ECS::Manager::getUpdatedEntities()
{
    auto actualScenesStack = _scenes;
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> updatedEntities{};

    for (auto it = actualScenesStack.rbegin(); it != actualScenesStack.rend(); it++) {
        updatedEntities.insert(updatedEntities.end(), (*it)->getEntities().begin(), (*it)->getEntities().end());
        if ((*it)->isOpaque())
            break;
    }
    return updatedEntities;
}

std::vector<std::shared_ptr<Engine::Abstracts::AScene>> Engine::ECS::Manager::getUpdatedScenes()
{
    auto actualScenesStack = _scenes;
    std::vector<std::shared_ptr<Engine::Abstracts::AScene>> updatedScenes{};

    for (auto it = actualScenesStack.rbegin(); it != actualScenesStack.rend(); it++) {
        updatedScenes.push_back(*it);
        if ((*it)->isOpaque()) {
            break;
        }
    }
    return updatedScenes;
}
