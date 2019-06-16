/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombTicking.cpp
*/

#include "ECS/Components/Timer.hpp"
#include "ECS/Manager.hpp"
#include "Components/BombTicker.hpp"
#include "Entities/Bomb.hpp"

Game::System::BombTicker::BombTicker()
    : ASystem("BombTicker")
{
}

void Game::System::BombTicker::update(double)
{
    auto &manager = Engine::ECS::Manager::getInstance();
    auto entities = manager.getUpdatedEntities();

    for (auto &entity : entities) {
        auto bomb = std::reinterpret_pointer_cast<Game::Entity::Bomb>(entity);

        if (bomb == nullptr)
            continue;

        try {
            auto timer = std::reinterpret_pointer_cast<Engine::ECS::Component::Timer>(bomb->getComponentByID("Timer"));
            auto model = std::reinterpret_pointer_cast<Engine::ECS::Component::Model3D>(
                bomb->getComponentByID("Model3D"));

            if (timer == nullptr || model == nullptr)
                continue;

            auto ratio = static_cast<float>(timer->getElapsed() / timer->getDuration() + 0.75);

            model->setScale({ratio, ratio, ratio});
        } catch (const ECSException<ECS_Entity> &) {}
    }
}
