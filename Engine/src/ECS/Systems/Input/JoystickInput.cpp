/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** KeyboardInput
*/

#include "ECS/Manager.hpp"
#include "Utils/Logger.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Systems/EventHandler.hpp"
#include "ECS/Systems/Input/JoystickInput.hpp"

Engine::ECS::System::JoystickInput::JoystickInput()
    : AInput{"JoystickInput"}
{
    auto renderer = std::dynamic_pointer_cast<Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));

    if (renderer->getWindow()->activateJoysticks(_joystickInfos))
        Logger::getInstance().info(std::to_string(_joystickInfos.size()) + " controllers connected");
    else
        Logger::getInstance().error("Failed to activate joystick");
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

bool Engine::ECS::System::JoystickInput::isKeyDown(irr::u8 controller, irr::u8 key) const
{
    const auto input = _controllers.find(controller);

    if (input == _controllers.end())
        return false;
    return ((input->second.buttonStates & (1u << key)) >> key);
}

irr::u16 Engine::ECS::System::JoystickInput::getPov(irr::u8 controller) const noexcept
{
    const auto input = _controllers.find(controller);

    if (input == _controllers.end())
        return 0;
    return input->second.pov;
}

irr::s16 Engine::ECS::System::JoystickInput::getAxis(irr::u8 controller, irr::u8 axis) const noexcept
{
    const auto input = _controllers.find(controller);

    if (input == _controllers.end())
        return 0;
    return input->second.axis[axis];
}

const decltype(Engine::ECS::System::JoystickInput::_joystickInfos) &Engine::ECS::System::JoystickInput::getJoystickInfos() const noexcept
{
    return _joystickInfos;
}