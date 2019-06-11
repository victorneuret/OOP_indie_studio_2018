/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GetAllEntities.cpp
*/

#include <iostream>
#include <memory>
#include <string>

#include "Entities/Particle.hpp"
#include "Systems/Particle.hpp"
#include "Exception/AException.hpp"
#include "ECS/Manager.hpp"
#include "Utils/Logger.hpp"
#include "Utils/Random.hpp"
#include "ECS/Components/Model3D.hpp"

Game::System::Particle::Particle()
    :ASystem("Particle")
{}

std::vector<std::shared_ptr<Engine::ECS::IEntity>> Game::System::Particle::getEntityList()
{
    return Engine::ECS::Manager::getInstance().getSceneByID("MainMenu")->getEntities();
}

void Game::System::Particle::applyMovement(const std::shared_ptr<Game::Entity::Particle> &particle)
{
    Engine::Math::Vec3<float> dir{(particle->getEndPoint().x - particle->getStartPoint().x), (particle->getEndPoint().y - particle->getStartPoint().y), (particle->getEndPoint().z - particle->getStartPoint().z)};

    auto norm = dir.normalize();
    auto getPos = (std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(particle->getComponentByID("Model3D"))->getNode()->getPosition());
    Engine::Math::Vec3<float> actualPos{getPos.X, getPos.Y, getPos.Z};
    //std::cout << std::to_string(actualPos.x) << " " << std::to_string(actualPos.y) << " " << std::to_string(actualPos.z) << std::endl;
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(particle->getComponentByID("Model3D"))->setPosition(actualPos + norm);
}

void Game::System::Particle::checkParticleState(const std::shared_ptr<Game::Entity::Particle> &particle)
{
    auto timer = std::dynamic_pointer_cast<Engine::ECS::Component::Timer>(particle->getComponentByID("Timer"));

    timer->execIfCooldownFinished();
}

void Game::System::Particle::update(double)
{
    auto tmp = getEntityList();

    for (auto &e : tmp) {
        auto ptr = std::dynamic_pointer_cast<Game::Entity::Particle>(e);

        if (ptr != nullptr) {
            checkParticleState(ptr);
            applyMovement(ptr);
        }
    }
}

void Game::System::Particle::createParticles(const double &quantity, const Engine::Math::Vec2<int> &duration, const Engine::Math::Vec3<float> &startPoint, const Engine::Math::Vec3<float> &endPoint, const double &momentum)
{
    for (float i = 0; i < quantity; ++i) {
        std::shared_ptr<Engine::ECS::IEntity> newParticle = std::make_shared<Game::Entity::Particle>(startPoint, endPoint, momentum, Random::getDouble(duration.x, duration.y));
        Engine::ECS::Manager::getInstance().getSceneByID("MainMenu")->addEntity(newParticle);
    }
    std::cout << "Successfully created " + std::to_string(quantity) + " particles" << std::endl;
}