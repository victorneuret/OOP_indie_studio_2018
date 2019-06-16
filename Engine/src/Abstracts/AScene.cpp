/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AScene
*/

#include <algorithm>

#include "Abstracts/AScene.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Image.hpp"

Engine::Abstracts::AScene::AScene(decltype(_id) id, decltype(_entities) entities, const bool opaque, const bool)
    : _id{std::move(id)}, _entities{std::move(entities)}, _opaque{opaque}
{}

Engine::Abstracts::AScene::~AScene()
{
    for (auto &entity : getEntities()) {
        entity->hide();
        switch (entity->getType()) {
            case Engine::ECS::IEntity::Type::MODEL3D:
                std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(entity->getComponentByID("Model3D"))->getNode()->remove();
                break;
            case Engine::ECS::IEntity::Type::MODEL2D:
                std::dynamic_pointer_cast<Engine::ECS::Component::Image>(entity->getComponentByID("Image"))->getGUIImage()->remove();
                break;
            default:
                break;
        }
    }
}

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
