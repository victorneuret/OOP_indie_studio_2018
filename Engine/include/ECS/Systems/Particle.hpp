/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GetAllEntities.hpp
*/

#pragma once

#include "ECS/Abstracts/ASystem.hpp"
#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Entities/Particle.hpp"
#include "Math/Vector/Vec3.hpp"

namespace Engine::ECS::System {
    class Particle;
}

class Engine::ECS::System::Particle : public Engine::ECS::ASystem {
private:
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> getEntityList();
    
public:
    Particle();

    void applyMovement(const std::shared_ptr<Engine::Entity::Particle> &particle);
    void createParticles(const double &quantity,
                        const Engine::Math::Vec2f &duration,
                        const Engine::Math::Vec3f &startPoint,
                        const Engine::Math::Vec3f &directionRange,
                        const double &momentum,
                        const std::string &sceneID);
    void checkParticleState(const std::shared_ptr<Engine::Entity::Particle> &particle);
    void update(double) final;
};
