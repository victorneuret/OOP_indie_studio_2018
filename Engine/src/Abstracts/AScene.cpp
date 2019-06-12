/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AScene
*/

#include <algorithm>

#include "Abstracts/AScene.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::Abstracts::AScene::AScene(decltype(_id) id, decltype(_entities) entities, const bool opaque, const bool updateChild)
    : _id{std::move(id)}, _entities{std::move(entities)}, _opaque{opaque}, _updateChild{updateChild}
{}

void Engine::Abstracts::AScene::addEntity(std::shared_ptr<ECS::IEntity> &entity)
{
    _entities.push_back(entity);
}

void Engine::Abstracts::AScene::removeEntity(const std::shared_ptr<ECS::IEntity> &entity)
{
    auto search = std::find(_entities.begin(), _entities.end(), entity);

    if (search != _entities.end())
        _entities.erase(search);
}

void Engine::Abstracts::AScene::removeEntityByID(size_t id)
{
    auto search = std::find_if(_entities.begin(), _entities.end(), [id](const std::shared_ptr<ECS::IEntity> &entity) {
        return entity->getID() == id;
    });

    if (search == _entities.end())
        throw ECSException<ECS_Entity>{"Entity " + std::to_string(id) + " not found"};
    _entities.erase(search);
}

std::shared_ptr<Engine::ECS::IEntity> &Engine::Abstracts::AScene::getEntityByID(const size_t id)
{
    auto search = std::find_if(_entities.begin(), _entities.end(), [id](const std::shared_ptr<ECS::IEntity> &entity) {
        return entity->getID() == id;
    });

    if (search == _entities.end())
        throw ECSException<ECS_Entity>{"Entity " + std::to_string(id) + " not found"};
    return *search;
}

decltype(Engine::Abstracts::AScene::_entities) &Engine::Abstracts::AScene::getEntities() noexcept
{
    return _entities;
}

const decltype(Engine::Abstracts::AScene::_entities) &Engine::Abstracts::AScene::getEntities() const noexcept
{
    return _entities;
}

const decltype(Engine::Abstracts::AScene::_id) &Engine::Abstracts::AScene::getID() const noexcept
{
    return _id;
}

decltype(Engine::Abstracts::AScene::_opaque) Engine::Abstracts::AScene::isOpaque() const noexcept
{
    return _opaque;
}

decltype(Engine::Abstracts::AScene::_updateChild) Engine::Abstracts::AScene::isUpdateChild() const noexcept
{
    return _updateChild;
}

void Engine::Abstracts::AScene::updateChild(const bool updateChild) noexcept
{
    _updateChild = updateChild;
}
