/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** JoystickInput
*/

#pragma once

#include <type_traits>
#include <irrlicht/irrlicht.h>

#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::System {
    class JoystickInput;
}

class Engine::ECS::System::JoystickInput final : public Engine::ECS::System::AInput {
protected:
    irr::u8 _controller{0};
    decltype(irr::SEvent::SJoystickEvent::Axis) _axis{0};

public:
    explicit JoystickInput(decltype(_controller) controller);
    bool OnEvent(const irr::SEvent &event) override;
    void update(double dt) override;
    const std::remove_all_extents<decltype(_axis)>::type &getAxis(irr::u8 axis);
};
