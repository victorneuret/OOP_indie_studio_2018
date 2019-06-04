/*
** EPITECH PROJECT, 2019    
** bomberman
** File description:
** ISystem.hpp
*/

#pragma once

#include <vector>

#include "ECS/Interfaces/IEntity.hpp"

namespace Engine::ECS {
    class ISystem;
}

class Engine::ECS::ISystem {
public:
    virtual ~ISystem() = default;
    virtual void update(double dt, std::vector<std::shared_ptr<IEntity>> &entities) = 0;
};
