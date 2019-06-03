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

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Interfaces/IComponent.hpp"
#include "ECS/Abstracts/AComponent.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

namespace Engine::ECS {
    template <typename T>
    class AEntity;

    static size_t getNextEntityID()
    {
        static size_t ID = 0;
        return ID++;
    }
}

template <typename T>
class Engine::ECS::AEntity : public IEntity {
protected:
    const size_t _id;
    const Type _type{};
    std::vector<std::shared_ptr<IComponent>> _components{};


public:
    AEntity(const Type type)
        : _id{getNextEntityID()}, _type{type}
    {
    }

    ~AEntity() override = default;

    size_t getID() const noexcept final
    {
        return _id;
    };

    const std::vector<std::shared_ptr<IComponent>> &getComponents() const noexcept
    {
        return _components;
    };

    void addComponent(std::shared_ptr<IComponent> &component)
    {
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

    std::shared_ptr<IComponent> &getComponentByID(const std::string &id)
    {
        auto pos = std::find_if(_components.begin(), _components.end(), [id](const std::shared_ptr<IComponent> &component) {
            return (component->getID() == id);
        });
        if (pos == _components.end())
            throw ECSException<ECS_Entity>("Component unknown");
        return *pos;
    };

    Type getType() const noexcept final
    {
        return _type;
    }
};
