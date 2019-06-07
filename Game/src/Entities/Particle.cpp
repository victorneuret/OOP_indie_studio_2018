/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Particle.cpp
*/

#include "Utils/Random.hpp"
#include "Entities/Particle.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Components/Timer.hpp"

Game::Entity::Particle::Particle(const Engine::Math::Vec3f &pos, const std::string &model)
    : AEntity(AEntity::Type::MODEL3D)
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(pos, model);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->addTexture("assets/models/blade_blue2.pcx");
    addComponent(_3DModel);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);

    std::shared_ptr<Engine::ECS::IComponent> _timer = std::make_shared<Engine::ECS::Component::Timer>(Random::getDouble(2, 10));
    addComponent(_timer);
}
