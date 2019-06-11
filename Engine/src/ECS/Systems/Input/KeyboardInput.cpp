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
    : ASystem{"KeyboardInput"}
{
    auto renderer = std::dynamic_pointer_cast<Renderer>(Manager::getInstance().getSystemByID("Renderer"));

    if (renderer == nullptr)
        throw ECSException<ECS_System>("Failed to get Renderer instance");
    renderer->getEventHandler()->add(this);
}

bool Engine::ECS::System::KeyboardInput::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        _keys[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
}

void Engine::ECS::System::KeyboardInput::update(double)
{}

bool Engine::ECS::System::KeyboardInput::isKeyDown(irr::EKEY_CODE key) const
{
    const auto pressed = _keys.find(key);

    if (pressed != _keys.end())
        return pressed->second;
    return false;
}