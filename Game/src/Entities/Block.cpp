/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Block.cpp
*/

#include <memory>

#include "Entities/Block.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Interfaces/IEntity.hpp"

Game::Entity::Block::Block(bool breakable, const Engine::Math::Vec3f &pos, const std::string &model)
    : AEntity(AEntity::Type::MODEL3D), _breakable(breakable)
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(pos, model);
    addComponent(_3DModel);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}
