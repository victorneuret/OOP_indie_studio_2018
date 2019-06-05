/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** KeyboardInput
*/

#include <iostream>

#include <ECS/Systems/JoystickInput.hpp>

Engine::ECS::System::JoystickInput::JoystickInput(decltype(_controller) controller)
    : AInput{"JoystickInput"}, _controller{controller}
{}

bool Engine::ECS::System::JoystickInput::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == _controller) {
        for (auto i = 0; i < irr::SEvent::SJoystickEvent::NUMBER_OF_AXES; i++)
            _axis[i] = event.JoystickEvent.Axis[i];
        for (auto i = 0; i < irr::SEvent::SJoystickEvent::NUMBER_OF_BUTTONS; i++)
            _keys[i] = event.JoystickEvent.IsButtonPressed(i);
    }
    return false;
}

const std::remove_all_extents<decltype(Engine::ECS::System::JoystickInput::_axis)>::type &Engine::ECS::System::JoystickInput::getAxis(irr::u8 axis)
{
    return _axis[axis];
}

void Engine::ECS::System::JoystickInput::update(double)
{}