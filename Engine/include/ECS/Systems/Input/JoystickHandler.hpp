/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** JoystickHandler.hpp
*/

#pragma once

#include <functional>
#include <irrlicht/irrlicht.h>

#include "ECS/Interfaces/InputType.hpp"

namespace Engine::ECS::System {
    class JoystickHandler;
}

class Engine::ECS::System::JoystickHandler final : public InputType {
public:
    enum CONTROLLER_BUTTONS {
        A,
        B,
        X,
        Y,
        LB,
        RB,
        SELECT,
        START,
        MENU
    };

protected:
    irr::u8 _controller;
    const std::map<INPUT_KEY, std::function<bool()>> _buttons = {
        {B_PRIMARY,    [&]() { return isButtonPressed(A); }},
        {B_START,  [&]() { return isButtonPressed(START); }},
    };

    bool isButtonPressed(irr::u8 key) const;

public:
    explicit JoystickHandler(decltype(_controller) controller);
    ~JoystickHandler() override = default;

    Engine::Math::Vec2f getPosition() const override;
    bool isKeyDown(irr::u8 key) const override;
};