/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AClickable.hpp
*/

#pragma once

namespace Engine::ECS::Entity {
    class IClickable;
}

class Engine::ECS::Entity::IClickable {
public:
    virtual ~IClickable() = default;
    virtual void onRelease() = 0;
    virtual void onPressed() = 0;
};
