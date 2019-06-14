/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** InputType.hpp
*/

#pragma once

#include "ECS/Interfaces/InputType.hpp"
#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS {
    class InputType;
}

class Engine::ECS::InputType {
public:
    enum INPUT_KEY {
        B_PRIMARY = (1 << 0),
        B_START = (1 << 1)
    };

    virtual ~InputType() = default;
    virtual bool isKeyDown(irr::u8 key) const = 0;
    virtual Engine::Math::Vec2f getPosition() const = 0;
};