/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** AComponent.hpp
*/

#pragma once

#include <cstddef>

#include "ECS/Interfaces/IComponent.hpp"

namespace Engine {
    namespace ECS {
        class AComponent;
    }
}

class Engine::ECS::AComponent : public Engine::ECS::IComponent {
protected:
    static size_t ID;

    const size_t _id{++ID};

public:
    virtual ~AComponent() = default;
};
