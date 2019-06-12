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
    class AComponent;
}

class Engine::ECS::AComponent : public IComponent {
protected:
    const std::string _id;

public:
    explicit AComponent(const std::string &id) : _id(std::string(id)) {};
    ~AComponent() override = default;

    std::string getID() const noexcept final
    {
        return _id;
    };
};
