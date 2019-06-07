/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include <memory>

#include "Entities/Player.hpp"
#include "Math/Vector/Vec3.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Components/Renderer.hpp"

Game::Entity::Player::Player(const Engine::Math::Vec3f &pos, const std::string &model)
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(pos, model);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->addTexture("assets/models/characters/BlackBombermanTextures.png");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->setScale(Engine::Math::Vec3f{12.f, 6.f, 12.f});
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->getNode()->setAnimationSpeed(30);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->getNode()->setFrameLoop(0, 27);
    addComponent(_3DModel);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}
