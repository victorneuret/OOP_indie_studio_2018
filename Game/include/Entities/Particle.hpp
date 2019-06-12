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
#include "Utils/Random.hpp"
#include "Math/Vector/Vec3.hpp"

namespace Game::Entity {
    class Particle;
}

class Game::Entity::Particle : public Engine::ECS::AEntity<Particle> {
protected:
    Engine::Math::Vec3<float> _startPoint{0, 0, 0};
    Engine::Math::Vec3<float> _endPoint{0, 0, 0};
    Engine::Math::Vec3<float> _spray{static_cast<float>(Random::getDouble(-0.5, 0.5)),
                                     static_cast<float>(Random::getDouble(-0.5, 0.5)),
                                     static_cast<float>(Random::getDouble(-0.5, 0.5))};
    double _momentum{0};

public:
    explicit Particle(const Engine::Math::Vec3<float> &startPoint,
                    const Engine::Math::Vec3<float> &endPoint,
                    const double &momentum, const double &duration,
                    const std::string &model = std::string("assets/models/particles/beach-ball.obj"));

    Particle(const Particle &) = delete;
    Particle &operator=(const Particle &) = delete;

    ~Particle() override = default;

    decltype(_startPoint) getStartPoint() const;
    decltype(_endPoint) getEndPoint() const;
    decltype(_spray) getSpray() const;
    double getMomentum() const;
};