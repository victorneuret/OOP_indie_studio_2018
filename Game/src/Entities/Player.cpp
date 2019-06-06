/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include <memory>

#include "Entities/Player.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Abstracts/Systems/AInput.hpp"
#include "ECS/Engine.hpp"

Game::Entity::Player::Player(const Engine::Math::Vec3f &pos, const std::string &model)
    : AEntity(AEntity::Type::MODEL3D)
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(pos, model);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->addTexture("assets/models/blade_blue2.pcx");
    addComponent(_3DModel);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}