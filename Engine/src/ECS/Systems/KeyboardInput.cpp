/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** KeyboardInput
*/

#include "ECS/Systems/KeyboardInput.hpp"

Engine::ECS::System::KeyboardInput::KeyboardInput()
        : AInput{"KeyboardInput"}
{}

bool Engine::ECS::System::KeyboardInput::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        _keys[event.KeyInput.Char] = event.KeyInput.PressedDown;
    return false;
}

void Engine::ECS::System::KeyboardInput::update(double)
{}