#include <utility>

#include <utility>

/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AScene
*/

#include <algorithm>

#include "Scenes/AScene.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::Scene::AScene::AScene(decltype(_id) id, decltype(_entities) entities, const bool opaque, const bool updateChild)
    : _id{std::move(id)}, _entities{std::move(entities)}, _opaque{opaque}, _updateChild{updateChild}
{}

void Engine::Scene::AScene::addEntity(std::shared_ptr<ECS::IEntity> &entity)
{
    _entities.push_back(entity);
}

void Engine::Scene::AScene::removeEntity(const std::shared_ptr<ECS::IEntity> &entity)
{
    auto search = std::find(_entities.begin(), _entities.end(), entity);

    if (search != _entities.end())
        _entities.erase(search);
}

std::shared_ptr<Engine::ECS::IEntity> &Engine::Scene::AScene::getEntityByID(const size_t id)
{
    auto search = std::find_if(_entities.begin(), _entities.end(), [id](const std::shared_ptr<ECS::IEntity> &entity) {
        return entity->getID() == id;
    });

    if (search == _entities.end())
        throw ECSException<ECS_Entity>{"Entity " + std::to_string(id) + " not found"};
    return *search;
}

decltype(Engine::Scene::AScene::_entities) &Engine::Scene::AScene::getEntities() noexcept
{
    return _entities;
}

const decltype(Engine::Scene::AScene::_entities) &Engine::Scene::AScene::getEntities() const noexcept
{
    return _entities;
}

const decltype(Engine::Scene::AScene::_id) &Engine::Scene::AScene::getID() const noexcept
{
    return _id;
}

decltype(Engine::Scene::AScene::_opaque) Engine::Scene::AScene::isOpaque() const noexcept
{
    return _opaque;
}

decltype(Engine::Scene::AScene::_updateChild) Engine::Scene::AScene::isUpdateChild() const noexcept
{
    return _updateChild;
}

void Engine::Scene::AScene::updateChild(const bool updateChild)
{
    _updateChild = updateChild;
}
