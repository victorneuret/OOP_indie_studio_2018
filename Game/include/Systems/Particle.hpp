/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GetAllEntities.hpp
*/

#pragma once

#include "ECS/Abstracts/ASystem.hpp"
#include "ECS/Interfaces/IEntity.hpp"

namespace Game::System {
    class Particle;
}

class Game::System::Particle : public Engine::ECS::ASystem<Particle> {
private:
public:

    Particle();

    void checkParticleState(const std::shared_ptr<Game::Entity::Particle> &particle);
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> getEntityList();
    void update(double) final;
};
