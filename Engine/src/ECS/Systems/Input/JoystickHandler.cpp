/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** JoystickHandler.cpp
*/

#include <memory>
#include <iostream>
#include <functional>

#include "ECS/Manager.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Systems/Input/JoystickInput.hpp"
#include "ECS/Systems/Input/JoystickHandler.hpp"

Engine::ECS::System::JoystickHandler::JoystickHandler(decltype(_controller) controller)
    : _controller{controller}
{}

bool Engine::ECS::System::JoystickHandler::isButtonPressed(irr::u8 key) const
{
    const auto input = std::dynamic_pointer_cast<JoystickInput>(Manager::getInstance().getSystemByID("JoystickInput"));

    if (input == nullptr)
        return false;

    return input->isKeyDown(_controller, key);
}

Engine::Math::Vec2f Engine::ECS::System::JoystickHandler::getPosition() const
{
    const auto &input = std::dynamic_pointer_cast<JoystickInput>(Manager::getInstance().getSystemByID("JoystickInput"));

    auto axisX = input->getAxis(_controller, irr::SEvent::SJoystickEvent::AXIS_X) / 32767.f;
    auto axisY = input->getAxis(_controller, irr::SEvent::SJoystickEvent::AXIS_Y) / -32767.f;

    return {
        axisX > - 0.05f && axisX < 0.05f ? 0 : axisX,
        axisY > - 0.05f && axisY < 0.05f ? 0 : axisY
    };
}

bool Engine::ECS::System::JoystickHandler::isKeyDown(irr::u8 key) const
{
    const auto &input = std::dynamic_pointer_cast<JoystickInput>(Manager::getInstance().getSystemByID("JoystickInput"));

    if (input == nullptr)
        return false;

    for (unsigned i = 0; i < sizeof(key) * 8; i++) {
        if (key & (1u << i)) {
            auto func = _buttons.find(static_cast<INPUT_KEY>(key & (1u << i)));

            if (func == _buttons.end() || !func->second())
                return false;
        }
    }
    return true;
}