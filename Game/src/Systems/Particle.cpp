/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GetAllEntities.cpp
*/

#include <iostream>
#include <memory>

#include "Entities/Particle.hpp"
#include "Systems/Particle.hpp"
#include "Exception/AException.hpp"
#include "ECS/Manager.hpp"
#include "Utils/Logger.hpp"
#include "Utils/Random.hpp"

Game::System::Particle::Particle()
    :ASystem("Particle")
{}

std::vector<std::shared_ptr<Engine::ECS::IEntity>> Game::System::Particle::getEntityList()
{
    return Engine::ECS::Manager::getInstance().getEntities();
}

void Game::System::Particle::checkParticleState(const std::shared_ptr<Game::Entity::Particle> &particle)
{
    auto timer = std::dynamic_pointer_cast<Engine::ECS::Component::Timer>(particle->getComponentByID("Timer"));

    timer->isCooldownFinished([&](){
        particle->hide();
    });
}

void Game::System::Particle::update(double)
{
    auto tmp = getEntityList();

    for (auto &e : tmp) {
        auto ptr = std::dynamic_pointer_cast<Game::Entity::Particle>(e);

        if (ptr != nullptr) {
            checkParticleState(ptr);
        }
    }
}

void Game::System::Particle::createParticles(const double &quantity, const double &minDuration, const double &maxDuration /*, Direction  */)
{
    for (float i = 0; i < quantity; ++i) {
        std::shared_ptr<Engine::ECS::IEntity> newParticle = std::make_shared<Game::Entity::Particle>(Engine::Math::Vec3f{(10 + i), 0, 10}, Random::getDouble(minDuration, maxDuration));
        Engine::ECS::Manager::getInstance().addEntity(newParticle);
    }
    std::cout << "Successfully created " + std::to_string(quantity) + " particles" << std::endl;
}