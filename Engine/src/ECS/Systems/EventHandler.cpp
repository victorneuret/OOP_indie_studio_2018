/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EventHandler.cpp
*/

#include <memory>

#include "ECS/Systems/EventHandler.hpp"
#include "ECS/Systems/Renderer.hpp"

Engine::ECS::System::EventHandler::EventHandler()
    : ASystem{"EventHandler"}
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

void Engine::ECS::System::EventHandler::update(double)
{}
