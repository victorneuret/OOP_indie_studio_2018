/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GetAllEntities.hpp
*/

#pragma once

#include "ECS/Abstracts/ASystem.hpp"
#include "ECS/Interfaces/IEntity.hpp"
#include "Entities/Particle.hpp"
#include "Math/Vector/Vec3.hpp"

namespace Game::System {
    class Particle;
}

class Game::System::Particle : public Engine::ECS::ASystem<Particle> {
private:

    std::vector<std::shared_ptr<Engine::ECS::IEntity>> getEntityList();

public:

    Particle();

    void applyMovement(const std::shared_ptr<Game::Entity::Particle> &particle);
    void createParticles(const double &quantity,
                        const Engine::Math::Vec2<float> &duration,
                        const Engine::Math::Vec3<float> &startPoint,
                        const Engine::Math::Vec3<float> &directionRange,
                        const double &momentum,
                        const std::string &sceneID);
    void checkParticleState(const std::shared_ptr<Game::Entity::Particle> &particle);
    void update(double) final;
};
