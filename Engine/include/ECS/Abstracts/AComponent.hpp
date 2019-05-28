/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AComponent.hpp
*/

#pragma once

#include <string>

#include "ECS/Interfaces/IComponent.hpp"

namespace Engine::ECS {
    template <typename T>
    class AComponent;
}

template <typename T>
class Engine::ECS::AComponent : public Engine::ECS::IComponent {
protected:
    const std::string _id;

public:
    AComponent(const std::string &id) : _id(std::string(id)) {};
    ~AComponent() override = default;

    decltype(_id) getID() const noexcept
    {
        return _id;
    };
};
