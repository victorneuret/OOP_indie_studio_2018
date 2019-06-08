/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AHoverable.hpp
*/

#pragma once

namespace Engine::ECS::Entity {
    class IHoverable;
}

class Engine::ECS::Entity::IHoverable {
public:
    virtual ~IHoverable() = default;
    virtual void onHover() = 0;
};
