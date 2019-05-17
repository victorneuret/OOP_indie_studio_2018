/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** AComponent.hpp
*/

#pragma once

#include <cstddef>
#include "Interfaces/IComponent.hpp"
namespace Engine {
    namespace ECS {
        class AComponent;
    }
}

class Engine::ECS::AComponent : public Engine::ECS::IComponent {
protected:
    size_t _id;

public:
    AComponent(const size_t id);
    virtual ~AComponent() = default;
};
