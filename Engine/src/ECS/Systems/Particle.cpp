/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GetAllEntities.cpp
*/

#include <memory>
#include <string>

#include "ECS/Entities/Particle.hpp"
#include "ECS/Systems/Particle.hpp"
#include "Exception/AException.hpp"
#include "ECS/Manager.hpp"
#include "Utils/Logger.hpp"
#include "Utils/Random.hpp"
#include "ECS/Components/Model3D.hpp"

Engine::ECS::System::Particle::Particle()
    : ASystem("Particle")
{}

std::vector<std::shared_ptr<Engine::ECS::IEntity>> &Engine::ECS::System::Particle::getEntityList()
{
    return Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntities();
}

void Engine::ECS::System::Particle::applyMovement(const std::shared_ptr<Engine::Entity::Particle> &particle)
{
    Engine::Math::Vec3<float> dir{
                (particle->getEndPoint().x - particle->getStartPoint().x),
                (particle->getEndPoint().y - particle->getStartPoint().y),
                (particle->getEndPoint().z - particle->getStartPoint().z)};

    auto spray = particle->getSpray();
    auto norm = dir.normalize() + spray;
    auto getPos = (std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>
        (particle->getComponentByID("Model3D"))->getNode()->getPosition());
    decltype(dir) actualPos{getPos.X, getPos.Y, getPos.Z};
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>
		(particle->getComponentByID("Model3D"))->setPosition(actualPos + (norm * particle->getMomentum()));
}

void Engine::ECS::System::Particle::checkParticleState(const std::shared_ptr<Engine::Entity::Particle> &particle)
{
    auto timer = std::dynamic_pointer_cast<Engine::ECS::Component::Timer>(particle->getComponentByID("Timer"));

    timer->execIfCooldownFinished();
}

void Engine::ECS::System::Particle::update(double)
{
    try {
        Engine::ECS::Manager::getInstance().getSceneByID("Game");
        auto &tmp = getEntityList();

        for (auto &e : tmp) {
            auto ptr = std::dynamic_pointer_cast<Engine::Entity::Particle>(e);

            if (ptr != nullptr) {
                checkParticleState(ptr);
                applyMovement(ptr);
            }
        }
    } catch (const ECSException<ECS_Scene> &e) {}

}

void Engine::ECS::System::Particle::createParticles(const double &quantity,
                                            const Engine::Math::Vec2<float> &duration,
                                            const Engine::Math::Vec3<float> &startPoint,
                                            const Engine::Math::Vec3<float> &directionRange,
                                            const double &momentum,
                                            const std::string &sceneID)
{
    for (float i = 0; i < quantity; ++i) {
        std::shared_ptr<Engine::ECS::IEntity> newParticle = std::make_shared<Engine::Entity::Particle>
			(startPoint, directionRange, momentum, Random::getDouble(duration.x, duration.y));
        Engine::ECS::Manager::getInstance().getSceneByID(sceneID)->addEntity(newParticle);
    }
}
