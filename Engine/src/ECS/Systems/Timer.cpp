/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.cpp
*/


#include "ECS/Manager.hpp"
#include "ECS/Systems/Timer.hpp"
#include "ECS/Components/Timer.hpp"

Engine::ECS::System::Timer::Timer()
    : ASystem{"Timer"}
{}

void Engine::ECS::System::Timer::update(double)
{
    for (const auto &scene : Manager::getInstance().getUpdatedScenes())
        for (auto &entity : scene->getEntities())
            try {
                if (entity == nullptr)
                    continue;
                std::dynamic_pointer_cast<Engine::ECS::Component::Timer>(
                        entity->getComponentByID("Timer"))->execIfCooldownFinished();
            } catch (...) {}
}
