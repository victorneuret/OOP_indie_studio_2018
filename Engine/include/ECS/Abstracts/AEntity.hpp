/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AEntity.hpp
*/

#pragma once

#include <cstddef>
#include <vector>
#include <algorithm>
#include <memory>

#include "Utils/Logger.hpp"
#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"
#include "ECS/Interfaces/IComponent.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

namespace Engine::ECS {
    template<typename T>
    class AEntity;

    static size_t getNextEntityID()
    {
        static size_t ID = 0;
        return ID++;
    }
}

template<typename T>
class Engine::ECS::AEntity : public IEntity {
protected:
    size_t _id;
    Type _type{};
    std::vector<std::shared_ptr<IComponent>> _components{};


public:
    explicit AEntity(const decltype(_type) type)
        : _id{getNextEntityID()}, _type{type}
    {
    }

    ~AEntity() override = default;

    decltype(_id) getID() const noexcept final
    {
        return _id;
    };

    const std::vector<std::shared_ptr<IComponent>> &getComponents() const noexcept final
    {
        return _components;
    };

    void addComponent(std::shared_ptr<IComponent> &component)
    {
        if (component == nullptr)
            throw MemoryException<Memory_Allocation_Failed>{"cannot add a null component"};
        _components.push_back(component);
    };

    void removeComponent(const std::string &id)
    {
        auto pos = std::find_if(_components.begin(), _components.end(), [id](const std::shared_ptr<IComponent> &component) {
            return (component->getID() == id);
        });
        if (pos == _components.end())
            throw ECSException<ECS_Entity>("Can't remove component " + id);
        _components.erase(pos);
    };

    std::shared_ptr<IComponent> &getComponentByID(const std::string &id) override
    {
        auto pos = std::find_if(_components.begin(), _components.end(), [id](const std::shared_ptr<IComponent> &component) {
            return (component->getID() == id);
        });
        if (pos == _components.end())
            throw ECSException<ECS_Entity>("Component unknown");
        return *pos;
    };

    decltype(_type) getType() const noexcept final
    {
        return _type;
    }

    void show() noexcept final
    {
        try {
            std::shared_ptr<Component::Renderer> renderer = std::dynamic_pointer_cast<Component::Renderer>(getComponentByID("Renderer"));
            renderer->setDoRender(true);
        } catch (const AException &exception) {
            Logger::getInstance().warning(exception.what());
        }
    };
    void hide() noexcept final
    {
        try {
            std::shared_ptr<Component::Renderer> renderer = std::dynamic_pointer_cast<Component::Renderer>(getComponentByID("Renderer"));
            renderer->setDoRender(false);
        } catch (const AException &exception) {
            Logger::getInstance().warning(exception.what());
        }
    };
};
