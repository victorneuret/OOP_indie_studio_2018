/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** IEntity.hpp
*/

#pragma once

#include "ECS/Interfaces/IComponent.hpp"

namespace Engine::ECS {
    class IEntity;
}

class Engine::ECS::IEntity {
public:
    virtual ~IEntity() = default;
    virtual size_t getID() const noexcept = 0;
    virtual std::shared_ptr<IComponent> &getComponentByID(const std::string &id) = 0;
    virtual const std::vector<std::shared_ptr<IComponent>> &getComponents() const noexcept = 0;
};
