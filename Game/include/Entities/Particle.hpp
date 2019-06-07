/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Particles.hpp
*/

#pragma once

#include <string>

#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Components/Timer.hpp"

namespace Game::Entity {
    class Particle;
}

class Game::Entity::Particle : public Engine::ECS::AEntity<Particle> {
public:
    explicit Particle( const Engine::Math::Vec3f &pos, const double &duration, const std::string &model = std::string("assets/models/tris.md2"));

    Particle(const Particle &) = delete;
    Particle &operator=(const Particle &) = delete;

    ~Particle() override = default;
};