/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MouseInput
*/

#pragma once

#include "Math/Vector/Vec2.hpp"
#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::System {
    class MouseInput;
}

class Engine::ECS::System::MouseInput final : public Engine::ECS::System::AInput {
private:
    enum MouseKey {
        LEFT,
        RIGHT,
        MIDDLE
    };
    Engine::Math::Vec2<decltype(irr::SEvent::SMouseInput::X)> _pos{};

public:
    MouseInput();
    bool OnEvent(irr::SEvent &event) final;
    const decltype(_pos) &pos() const noexcept;
};
