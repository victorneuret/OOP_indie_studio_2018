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
    virtual const std::string &getID() const noexcept = 0;
    virtual void update(double dt) = 0;

};
