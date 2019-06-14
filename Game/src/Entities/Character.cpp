/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.cpp
*/

#include <cmath>

#include "Entities/Character.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "Systems/Map.hpp"
#include "ECS/Manager.hpp"
#include "Entities/Bomb.hpp"

Game::Entity::Character::Character(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model)
    : AEntity(AEntity::Type::MODEL3D), _pos{pos}, _speed{30}
{
    auto _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(_pos, model);
    auto _3DModelPtr = std::dynamic_pointer_cast<Engine::ECS::IComponent>(_3DModel);

    _3DModel->addTexture(texture);
    _3DModel->setScale(Engine::Math::Vec3f{12.f, 6.f, 12.f});
    _3DModel->getNode()->setAnimationSpeed(30);
    _3DModel->getNode()->setFrameLoop(27, 76);
    _3DModel->getNode()->setRotation(irr::core::vector3df{0, ((_pos.x == INDEX_TO_POS(0)) ? static_cast<float>(-90) : static_cast<float>(90)), 0});
    addComponent(_3DModelPtr);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}

void Game::Entity::Character::placeBomb() const noexcept
{
    auto entities = Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntities();

    std::shared_ptr<Engine::ECS::IEntity> bomb = std::make_shared<Game::Entity::Bomb>(Engine::Math::Vec2i{static_cast<int>(round(_pos.x / 10) + 1), static_cast<int>(round(_pos.y / 10) + 1)}, _range);
    Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(bomb);
}

void Game::Entity::Character::move(const Engine::Math::Vec2f &speed, float timeMove) noexcept
{
    auto _3DModel = getComponentByID("Model3D");
    _pos.x += speed.x * _speed * timeMove;
    _pos.y += speed.y * _speed * timeMove;
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->setPosition(Engine::Math::Vec3f{_pos.x, 0, _pos.y});
}

const decltype(Game::Entity::Character::_speed) &Game::Entity::Character::getSpeed() const noexcept
{
    return _speed;
}


void Game::Entity::Character::setSpeed(const decltype(_speed) &speed) noexcept
{
    _speed = speed;
}
