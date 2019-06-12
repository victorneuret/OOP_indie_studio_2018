/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AEntity.cpp
*/

#include "ECS/Abstracts/AEntity.hpp"

size_t Engine::ECS::getNextEntityID() noexcept
{
    static size_t ID = 0;
    return ID++;
}

Engine::ECS::AEntity::AEntity(const decltype(_type) type)
    : _id{getNextEntityID()}, _type{type}
{
}

decltype(Engine::ECS::AEntity::_id) Engine::ECS::AEntity::getID() const noexcept
{
    return _id;
}

void Engine::ECS::AEntity::show() noexcept
{
    try {
        std::shared_ptr<Component::Renderer> renderer = std::dynamic_pointer_cast<Component::Renderer>(getComponentByID("Renderer"));
        renderer->setDoRender(true);
    } catch (const AException &exception) {
        Logger::getInstance().warning(exception.what());
    }
}

void Engine::ECS::AEntity::hide() noexcept
{
    try {
        std::shared_ptr<Component::Renderer> renderer = std::dynamic_pointer_cast<Component::Renderer>(getComponentByID("Renderer"));
        renderer->setDoRender(false);
    } catch (const AException &exception) {
        Logger::getInstance().warning(exception.what());
    }
}

void Engine::ECS::AEntity::addComponent(std::shared_ptr<Engine::ECS::IComponent> &component)
{
    if (component == nullptr)
        throw MemoryException<Memory_Allocation_Failed>{"cannot add a null component"};
    _components.push_back(component);
}

void Engine::ECS::AEntity::removeComponent(const std::string &id)
{
    auto pos = std::find_if(_components.begin(), _components.end(), [id](const std::shared_ptr<IComponent> &component) {
        return (component->getID() == id);
    });

    if (pos == _components.end())
        throw ECSException<ECS_Entity>("Can't remove component " + id);
    _components.erase(pos);
}

const std::vector<std::shared_ptr<Engine::ECS::IComponent>> &Engine::ECS::AEntity::getComponents() const noexcept
{
    return _components;
}

std::shared_ptr<Engine::ECS::IComponent> &Engine::ECS::AEntity::getComponentByID(const std::string &id)
{
    auto pos = std::find_if(_components.begin(), _components.end(), [id](const std::shared_ptr<IComponent> &component) {
        return (component->getID() == id);
    });

    if (pos == _components.end())
        throw ECSException<ECS_Entity>("Component " + id + " unknown");
    return *pos;
}

decltype(Engine::ECS::AEntity::_type) Engine::ECS::AEntity::getType() const noexcept
{
    return _type;
}
