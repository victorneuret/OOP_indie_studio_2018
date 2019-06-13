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

namespace Engine::Entity {
    class Particle;
}

class Engine::Entity::Particle : public Engine::ECS::AEntity {
protected:
    Engine::Math::Vec3f _startPoint{0, 0, 0};
    Engine::Math::Vec3f _endPoint{0, 0, 0};
    Engine::Math::Vec3f _spray{static_cast<float>(Random::getDouble(-0.5, 0.5)),
                                     static_cast<float>(Random::getDouble(-0.5, 0.5)),
                                     static_cast<float>(Random::getDouble(-0.5, 0.5))};
    double _momentum{0};

public:
    Particle(const Engine::Math::Vec3<float> &startPoint,
                    const Engine::Math::Vec3<float> &endPoint,
                    const double &momentum, const double &duration,
                    const std::string &model = std::string("assets/models/particles/beach-ball.obj"));

    Particle(const Particle &) = delete;
    Particle &operator=(const Particle &) = delete;

    ~Particle() override = default;

    decltype(_startPoint) getStartPoint() const noexcept;
    decltype(_endPoint) getEndPoint() const noexcept;
    decltype(_spray) getSpray() const noexcept;
    double getMomentum() const noexcept;
};