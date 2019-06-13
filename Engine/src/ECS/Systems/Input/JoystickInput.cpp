/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** KeyboardInput
*/

#include <iostream>

#include "ECS/Manager.hpp"
#include "Utils/Logger.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Systems/EventHandler.hpp"
#include "ECS/Systems/Input/JoystickInput.hpp"

Engine::ECS::System::JoystickInput::JoystickInput()
    : AInput{"JoystickInput"}
{
    auto renderer = std::dynamic_pointer_cast<Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));

    irr::core::array<irr::SJoystickInfo> joystickInfo{};

    if (!renderer->getWindow()->activateJoysticks(joystickInfo))
        Logger::getInstance().error("Failed to activate joystick");
    else
        Logger::getInstance().info(std::to_string(joystickInfo.size()) + " controllers connected");
}

bool Engine::ECS::System::JoystickInput::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT) {
        _controllers[event.JoystickEvent.Joystick] = {};
        _controllers[event.JoystickEvent.Joystick].pov = event.JoystickEvent.POV;

        for (auto i = 0; i < irr::SEvent::SJoystickEvent::NUMBER_OF_AXES; i++)
            _controllers[event.JoystickEvent.Joystick].axis[i] = event.JoystickEvent.Axis[i];

        _controllers[event.JoystickEvent.Joystick].buttonStates = event.JoystickEvent.ButtonStates;
    }
    return false;
}

bool Engine::ECS::System::JoystickInput::isKeyDown(irr::u8 axis, irr::u8 key) const
{
    const auto controller = _controllers.find(axis);

    if (controller == _controllers.end())
        return false;
    return ((controller->second.buttonStates & (1u << key)) >> key);
}
