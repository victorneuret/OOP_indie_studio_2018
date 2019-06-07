/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ButtonEvent.cpp
*/

#include "ECS/Engine.hpp"
#include "ECS/Systems/Event/ButtonEvent.hpp"

Engine::ECS::System::ButtonEvent::ButtonEvent()
    : AEvent{"ButtonEvent"}
{}

bool Engine::ECS::System::ButtonEvent::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        const auto ID = event.GUIEvent.Element->getID();

    }
    return false;
}