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

    void applyMovement(const std::shared_ptr<Game::Entity::Particle> &particle, const double &dt);
    void createParticles(const double &quantity, const double &minDuration, const double &maxDuration, const Engine::Math::Vec3<float> &startPoint, const Engine::Math::Vec3<float> &endPoint, const double &momentum);
    void checkParticleState(const std::shared_ptr<Game::Entity::Particle> &particle);
    void update(double) final;
};
