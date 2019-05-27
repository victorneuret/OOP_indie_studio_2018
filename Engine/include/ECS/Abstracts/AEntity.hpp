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

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Interfaces/IComponent.hpp"
#include "ECS/Abstracts/AComponent.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

namespace Engine::ECS {
    template <typename T>
    class AEntity;

    static size_t getNextID()
    {
        static size_t ID = 0;
        return ID++;
    }
}

template <typename T>
class Engine::ECS::AEntity : public Engine::ECS::IEntity {
private:

protected:
    const size_t _id;
    std::vector<Engine::ECS::IComponent> _components{};

public:
    AEntity()
        : _id{Engine::ECS::getNextID()}
    {
    }

    ~AEntity() override = default;

    decltype(_id) getID() const noexcept
    {
        return _id;
    };

    const decltype(_components) &getComponents() const noexcept
    {
        return _components;
    };

    void addComponent(const Engine::ECS::AComponent<T> &component)
    {
        _components.push_back(component);
    };

    void removeComponent()
    {
        _components.erase(std::remove(_components.begin(), _components.end(), _id), _components.end());
    };

    IComponent &getComponentByID(const size_t ID)
    {
        auto search = std::find(_components.begin(), _components.end(), ID);

        if (search == _components.end())
            throw ECSException<ECS_Entity>("Component unknown");
        return *search;
    };
};
