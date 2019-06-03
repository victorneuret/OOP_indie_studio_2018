/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** KeyboardInput
*/

#include "ECS/Systems/KeyboardInput.hpp"

bool Engine::ECS::System::KeyboardInput::OnEvent(irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        _keys[event.KeyInput.Char] = event.KeyInput.PressedDown;
    return false;
}