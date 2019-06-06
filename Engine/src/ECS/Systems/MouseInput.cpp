/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MouseInput
*/

#include "ECS/Systems/MouseInput.hpp"

Engine::ECS::System::MouseInput::MouseInput()
    : AInput{"MouseInput"}
{}

bool Engine::ECS::System::MouseInput::OnEvent(const irr::SEvent &event)
{
    if (event.EventType != irr::EET_MOUSE_INPUT_EVENT)
        return false;
    _keys[MouseKey::LEFT] = event.MouseInput.isLeftPressed();
    _keys[MouseKey::MIDDLE] = event.MouseInput.isMiddlePressed();
    _keys[MouseKey::RIGHT] = event.MouseInput.isRightPressed();
    _pos = {event.MouseInput.X, event.MouseInput.Y};
    return false;
}

const decltype(Engine::ECS::System::MouseInput::_pos) &Engine::ECS::System::MouseInput::pos() const noexcept
{
    return _pos;
}

void Engine::ECS::System::MouseInput::update(double)
{}
