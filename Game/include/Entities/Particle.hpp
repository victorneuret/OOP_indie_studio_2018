/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Particle.hpp
*/

#pragma once

#include <string>

#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Renderer.hpp"

namespace Game::Entity {
    class Particle;
}

class Game::Entity::Particle : public Engine::ECS::AEntity<Particle> {
public:
    explicit Particle(const Engine::ECS::System::Renderer &renderer, const Engine::Math::Vec3f &pos, const double &duration, const std::string &model = std::string("assets/models/weapon.md2"), const std::string &texture = std::string("assets/models/weapon.pcx"));

    Particle(const Particle &) = delete;
    Particle &operator=(const Particle &) = delete;

    ~Particle() override = default;
};