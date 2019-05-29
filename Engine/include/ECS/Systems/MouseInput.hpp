/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MouseInput
*/

#pragma once

#include "Math/Vector/Vec2.hpp"

#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::Systems {
    class MouseInput;
}

class Engine::ECS::Systems::MouseInput : public Engine::ECS::Systems::AInput {
private:
    enum MouseKey {
        LEFT,
        RIGHT,
        MIDDLE
    };
    Engine::Math::Vec2<decltype(irr::SEvent::SMouseInput::X)> _pos;

public:
    bool OnEvent(irr::SEvent &event) final;
    const decltype(_pos) &pos() const noexcept;
};