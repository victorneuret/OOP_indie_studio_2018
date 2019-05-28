/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** IComponent.hpp
*/

#pragma once

#include <string>

namespace Engine::ECS {
    class IComponent;
}

class Engine::ECS::IComponent {
public:
    virtual ~IComponent() = default;
    virtual std::string getID() const noexcept = 0;
};
