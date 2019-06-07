/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AInput.cpp
*/

#include "ECS/Engine.hpp"
#include "ECS/Systems/EventHandler.hpp"
#include "ECS/Abstracts/Systems/AInput.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::ECS::System::AInput::AInput(const std::string &id)
    : ASystem{id}
{
    auto eventHandler = std::dynamic_pointer_cast<EventHandler>(Engine::getInstance().getSystemsByID("EventHandler"));

    if (eventHandler == nullptr)
        throw ECSException<ECS_System>("Failed to get EventHandler instance");

    eventHandler->add(this);
}

bool Engine::ECS::System::AInput::isKeyDown(const decltype(irr::SEvent::SKeyInput::Char) &key)
{
    if (_keys.find(key) != _keys.end())
        return _keys[key];
    return false;
}