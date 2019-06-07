/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EventHandler.cpp
*/

#include <memory>

#include "ECS/Systems/EventHandler.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Engine.hpp"

Engine::ECS::System::EventHandler::EventHandler()
    : ASystem(TYPE_STR)
{}

void Engine::ECS::System::EventHandler::add(irr::IEventReceiver *handler)
{
    _handlers.push_back(handler);
}

bool Engine::ECS::System::EventHandler::OnEvent(const irr::SEvent &event)
{
    for (auto &c : _handlers) {
        if (c->OnEvent(event))
            return true;
    }
    return false;
}