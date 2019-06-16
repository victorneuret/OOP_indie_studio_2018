/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.cpp
*/


#include "ECS/Manager.hpp"
#include "ECS/Systems/Timer.hpp"
#include "ECS/Components/Timer.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::ECS::System::Timer::Timer()
    : ASystem{"Timer"}
{}

void Engine::ECS::System::Timer::update(double)
{
    for (auto &entity :  Manager::getInstance().getUpdatedEntities()) {
        if (entity == nullptr)
            continue;
        try {
            auto timer = std::dynamic_pointer_cast<Engine::ECS::Component::Timer>(entity->getComponentByID("Timer"));
            if (timer != nullptr)
                timer->execIfCooldownFinished();
        } catch (const ECSException<ECS_Entity> &) {}
    }
}
