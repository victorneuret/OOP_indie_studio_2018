/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.cpp
*/

#include <Entities/Character.hpp>

#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "Systems/Map.hpp"
#include "ECS/Manager.hpp"
#include "Entities/Bomb.hpp"

Game::Entity::Character::Character(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model)
    : AEntity(AEntity::Type::MODEL3D), _pos{pos}
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(_pos, model);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->addTexture(texture);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->setScale(Engine::Math::Vec3f{12.f, 6.f, 12.f});
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->getNode()->setAnimationSpeed(30);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->getNode()->setFrameLoop(27, 76);
    if (_pos.x == INDEX_TO_POS(0))
        std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->getNode()->setRotation(irr::core::vector3df{0, -90, 0});
    else
        std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->getNode()->setRotation(irr::core::vector3df{0, 90, 0});
    addComponent(_3DModel);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}

#include <iostream>

void Game::Entity::Character::placeBomb() const noexcept
{
    std::cout << "place bomb" << std::endl;
    auto entities =  Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntities();

    std::shared_ptr<Engine::ECS::IEntity> bomb = std::make_shared<Game::Entity::Bomb>(Engine::Math::Vec2i{static_cast<int>(2), static_cast<int>(1)});
    Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(bomb);
}

void Game::Entity::Character::move(const Engine::Math::Vec2f &speed, double time) noexcept
{
    auto _3DModel = getComponentByID("Model3D");
    _pos.x += speed.x * (time);
    _pos.y += speed.y * (time);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->setPosition(Engine::Math::Vec3f{_pos.x, 0, _pos.y});
}
