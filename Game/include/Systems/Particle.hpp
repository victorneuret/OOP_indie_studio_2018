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

namespace Game::System {
    class Particle;
}

class Game::System::Particle : public Engine::ECS::ASystem<Particle> {
private:

    std::vector<std::shared_ptr<Engine::ECS::IEntity>> getEntityList();

public:

    Particle();

    void createParticles(const double &quantity, const double &minDuration, const double &maxDuration);
    void checkParticleState(const std::shared_ptr<Game::Entity::Particle> &particle);
    void update(double) final;
};
