/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Particle.cpp
*/

#include "Utils/Random.hpp"
#include "ECS/Entities/Particle.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Components/Timer.hpp"
#include "ECS/Manager.hpp"

Engine::Entity::Particle::Particle(const Engine::Math::Vec3f &startPoint,
                                const Engine::Math::Vec3<float> &endPoint,
                                const double &momentum, const double &duration,
                                const Engine::Math::Vec2i &colors,
                                const std::string &model)
    : AEntity{AEntity::Type::MODEL3D}, _startPoint{startPoint}, _endPoint{endPoint}, _momentum{momentum}
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(startPoint, model);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->addTexture("assets/models/particles/" + std::to_string(Random::getSigned(colors.x, colors.y)) + ".png");
    addComponent(_3DModel);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);

    std::shared_ptr<Engine::ECS::IComponent> _timer = std::make_shared<Engine::ECS::Component::Timer>(duration,
        [&](){
            std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(getComponentByID("Model3D"))->getNode()->remove();
            Engine::ECS::Manager::getInstance().getSceneByID("Game")->removeEntityByID(getID());
            hide();
        });
    addComponent(_timer);
}

decltype(Engine::Entity::Particle::_startPoint) Engine::Entity::Particle::getStartPoint() const noexcept
{
    return _startPoint;
}

decltype(Engine::Entity::Particle::_endPoint) Engine::Entity::Particle::getEndPoint() const noexcept
{
    return _endPoint;
}

double Engine::Entity::Particle::getMomentum() const noexcept
{
    return _momentum;
}

decltype(Engine::Entity::Particle::_spray) Engine::Entity::Particle::getSpray() const noexcept
{
    return _spray;
}
