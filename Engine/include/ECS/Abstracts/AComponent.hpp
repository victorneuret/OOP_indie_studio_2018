/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AComponent.hpp
*/

#pragma once

#include <cstddef>

#include "ECS/Interfaces/IComponent.hpp"

namespace Engine::ECS {
    class AComponent;
}

class Engine::ECS::AComponent : public Engine::ECS::IComponent {
private:

protected:
    size_t _id{++ID};

public:
    static size_t ID;

    ~AComponent() override = default;

    decltype(_id) id() const noexcept;
};
