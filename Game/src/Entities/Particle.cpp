/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Particle.cpp
*/

#include "Utils/Random.hpp"
#include "Entities/Particle.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Components/Timer.hpp"

Game::Entity::Particle::Particle(const Engine::Math::Vec3f &startPoint,
                                const Engine::Math::Vec3<float> &endPoint,
                                const double &momentum, const double &duration,
                                const std::string &model)
    : AEntity{AEntity::Type::MODEL3D}, _startPoint{startPoint}, _endPoint{endPoint}, _momentum{momentum}
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(startPoint, model);
    addComponent(_3DModel);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);

    std::shared_ptr<Engine::ECS::IComponent> _timer = std::make_shared<Engine::ECS::Component::Timer>(duration,
        [&](){
            Engine::ECS::AEntity::hide();
        });
    addComponent(_timer);
}

Engine::Math::Vec3<float> Game::Entity::Particle::getStartPoint() const
{
    return _startPoint;
}

Engine::Math::Vec3<float> Game::Entity::Particle::getEndPoint() const
{
    return _endPoint;
}

double Game::Entity::Particle::getMomentum() const
{
    return _momentum;
}

Engine::Math::Vec3<float> Game::Entity::Particle::getSpray() const
{
    return _spray;
}
