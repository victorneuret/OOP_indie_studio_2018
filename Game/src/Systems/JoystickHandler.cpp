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
#include "Systems/JoystickHandler.hpp"

Game::System::JoystickHandler::JoystickHandler(decltype(_controller) controller)
    : _controller{controller}
{}

bool Game::System::JoystickHandler::isButtonPressed(irr::u8 key) const
{
    const auto input = std::dynamic_pointer_cast<Engine::ECS::System::JoystickInput>(
        Engine::ECS::Manager::getInstance().getSystemByID("JoystickInput"));

    if (input == nullptr)
        return false;

    return input->isKeyDown(_controller, key);
}

Engine::Math::Vec2f Game::System::JoystickHandler::getPosition() const
{
    const auto &input = std::dynamic_pointer_cast<Engine::ECS::System::JoystickInput>(
        Engine::ECS::Manager::getInstance().getSystemByID("JoystickInput"));

    auto axisX = -input->getAxis(_controller, irr::SEvent::SJoystickEvent::AXIS_X) / 32767.f;
    auto axisY = -input->getAxis(_controller, irr::SEvent::SJoystickEvent::AXIS_Y) / -32767.f;

    return {
        axisX > -MIN_AXIS && axisX < MIN_AXIS ? 0 : axisX,
        axisY > -MIN_AXIS && axisY < MIN_AXIS ? 0 : axisY
    };
}

bool Game::System::JoystickHandler::isKeyDown(irr::u8 key) const
{
    const auto &input = std::dynamic_pointer_cast<Engine::ECS::System::JoystickInput>(
        Engine::ECS::Manager::getInstance().getSystemByID("JoystickInput"));

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