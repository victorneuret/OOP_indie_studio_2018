/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** KeyboardInput
*/

#include "ECS/Manager.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/Systems/AInput.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::ECS::System::KeyboardInput::KeyboardInput()
    : AInput{"KeyboardInput"}
{}


bool Engine::ECS::System::KeyboardInput::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        _keys[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
}

bool Engine::ECS::System::KeyboardInput::isKeyDown(irr::EKEY_CODE key) const
{
    const auto pressed = _keys.find(key);

    if (pressed != _keys.end())
        return pressed->second;
    return false;
}
