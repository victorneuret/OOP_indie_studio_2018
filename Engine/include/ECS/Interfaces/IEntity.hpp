/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** IEntity.hpp
*/

#pragma once

#include <vector>

#include "ECS/Interfaces/IComponent.hpp"

namespace Engine::ECS {
    class IEntity;
}

class Engine::ECS::IEntity {
public:
    enum class Type {
        MODEL3D = 1,
        MODEL2D = 2,
        TEXT = 3,
        BUTTON = 4,
        SLIDER = 5,
    };

public:
    virtual ~IEntity() = default;
    virtual size_t getID() const noexcept = 0;
    virtual std::shared_ptr<IComponent> &getComponentByID(const std::string &id) = 0;
    virtual const std::vector<std::shared_ptr<IComponent>> &getComponents() const noexcept = 0;
    virtual Type getType() const noexcept = 0;
};
