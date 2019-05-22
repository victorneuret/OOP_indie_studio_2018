/*
** EPITECH PROJECT, 2019    
** bomberman
** File description:
** ISystem.hpp
*/

#pragma once

namespace Engine::ECS {
    class ISystem;
}

class Engine::ECS::ISystem {
public:
    virtual ~ISystem() = default;
    virtual void update(double dt) = 0;
};