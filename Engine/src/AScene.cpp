/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Scene
*/

#include <algorithm>

#include "AScene.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::AScene::AScene(const SceneType type, decltype(Engine::AScene::_entities) &entities, const bool opaque, const bool updateChild)
    : _type{type}, _entities{entities}, _opaque{opaque}, _updateChild{updateChild}
{}

void Engine::AScene::addEntity(std::shared_ptr<Engine::ECS::IEntity> &entity)
{
    _entities.push_back(entity);
}

void Engine::AScene::removeEntity(const std::shared_ptr<Engine::ECS::IEntity> &entity)
{
    auto search = std::find(_entities.begin(), _entities.end(), entity);

    if (search != _entities.end())
        _entities.erase(search);
}

std::shared_ptr<Engine::ECS::IEntity> &Engine::AScene::getEntityByID(const size_t id)
{
    auto search = std::find_if(_entities.begin(), _entities.end(), [id](const std::shared_ptr<Engine::ECS::IEntity> &entity) {
        return entity->getID() == id;
    });

    if (search == _entities.end())
        throw ECSException<ECS_Entity>{"Entity " + std::to_string(id) + " not found"};
    return *search;
}

decltype(Engine::AScene::_entities) &Engine::AScene::getEntities() noexcept
{
    return _entities;
}

const decltype(Engine::AScene::_entities) &Engine::AScene::getEntities() const noexcept
{
    return _entities;
}

void Engine::AScene::updateChild(const bool updateChild)
{
    _updateChild = updateChild;
}
