/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ASystem.hpp
*/

#pragma once

#include "ECS/Interfaces/ISystem.hpp"

namespace Engine::ECS {
    template<typename T>
    class ASystem;
}

template<typename T>
class Engine::ECS::ASystem : public ISystem {
public:
    ~ASystem() override = default;

    void update(double dt) override = 0;
};

