/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** IComponent.hpp
*/

#pragma once

namespace Engine {
    namespace ECS {
        class IComponent;
    }
}

class Engine::ECS::IComponent {
public:
    virtual ~IComponent() = default;
};
