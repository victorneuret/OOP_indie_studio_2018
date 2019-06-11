/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AInput.cpp
*/

#include "ECS/Manager.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/Systems/AInput.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::ECS::System::AInput::AInput(const std::string &id)
    : ASystem{id}
{
    auto renderer = std::dynamic_pointer_cast<Renderer>(Manager::getInstance().getSystemByID("Renderer"));

    if (renderer == nullptr)
        throw ECSException<ECS_System>("Failed to get Renderer instance");
    renderer->getEventHandler()->add(this);
}

void Engine::ECS::System::AInput::update(double)
{}
