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
    auto actualScenesStack = Manager::getInstance().getUpdatedScenes();

    for (const auto &scene : actualScenesStack)
        for (auto &entity : scene->getEntities()) {
            if (entity == nullptr)
                continue;
            try {
                auto timer = std::dynamic_pointer_cast<Engine::ECS::Component::Timer>(entity->getComponentByID("Timer"));
                if (timer != nullptr)
                    timer->execIfCooldownFinished();
            } catch (...) {}
        }
}
