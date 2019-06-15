/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.cpp
*/

#include <cmath>
#include <iostream>

#include "Entities/Character.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "Systems/Map.hpp"
#include "ECS/Manager.hpp"
#include "Entities/Bomb.hpp"
#include "Entities/Block.hpp"

Game::Entity::Character::Character(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model)
    : AEntity(AEntity::Type::MODEL3D), _pos{pos}, _speed{30}
{
    auto _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(_pos, model);
    auto _3DModelPtr = std::dynamic_pointer_cast<Engine::ECS::IComponent>(_3DModel);

    _3DModel->addTexture(texture);
    _3DModel->setScale(Engine::Math::Vec3f{12.f, 6.f, 12.f});
    _3DModel->getNode()->setAnimationSpeed(40);
    _3DModel->getNode()->setFrameLoop(27, 76);
    _3DModel->getNode()->setRotation(irr::core::vector3df{0, ((_pos.x == INDEX_TO_POS(0)) ? static_cast<float>(-90) : static_cast<float>(90)), 0});
    addComponent(_3DModelPtr);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}

void Game::Entity::Character::placeBomb() noexcept
{
    if (_bombStock == 0)
        return;
    auto entities = Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntities();

    std::shared_ptr<Engine::ECS::IEntity> bomb = std::make_shared<Game::Entity::Bomb>(getID(), Engine::Math::Vec2i{static_cast<int>(round(_pos.x / 10) + 1), static_cast<int>(round(_pos.y / 10) + 1)}, _range);
    Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(bomb);
    _bombStock--;
}

void Game::Entity::Character::move(const Engine::Math::Vec2f &speed, float timeMove) noexcept
{
    auto model3D = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(getComponentByID("Model3D"));
    decltype(_pos) tmpPos{_pos};
    decltype(_pos) tmpPos2{_pos};

    tmpPos.x += speed.x * _speed * timeMove;
    tmpPos.y += speed.y * _speed * timeMove;

    if (tmpPos.x < 0)
        tmpPos.x = 0;
    else if (tmpPos.x + INDEX_TO_POS(1) > INDEX_TO_POS(MAP_WIDTH))
        tmpPos.x = INDEX_TO_POS(MAP_WIDTH - 1);
    if (tmpPos.y < 0)
        tmpPos.y = 0;
    else if (tmpPos.y + INDEX_TO_POS(1) > INDEX_TO_POS(MAP_HEIGHT))
        tmpPos.y = INDEX_TO_POS(MAP_HEIGHT - 1);

    auto map = std::dynamic_pointer_cast<Game::System::Map>(Engine::ECS::Manager::getInstance().getSystemByID("Map"));
    if (map == nullptr || map->getActualMap().empty())
        return;
    auto boxX = map->getBlocks()[static_cast<size_t>(round(tmpPos.x / 10))][static_cast<size_t>(round(_pos.y / 10))];
    auto boxY = map->getBlocks()[static_cast<size_t>(round(_pos.x / 10))][static_cast<size_t>(round(tmpPos.y / 10))];

    if (speed.x > 0 && speed.x > speed.y && speed.x > speed.y * -1) {
        model3D->getNode()->setRotation(irr::core::vector3df(0, 270, 0));
    } else if (speed.x < 0 && speed.x < speed.y && speed.x < speed.y * -1) {
        model3D->getNode()->setRotation(irr::core::vector3df(0, 90, 0));
    } else if (speed.y > 0 && speed.y > speed.x && speed.y > speed.x * -1) {
        model3D->getNode()->setRotation(irr::core::vector3df(0, 180, 0));
    } else if (speed.y < 0 && speed.y < speed.x && speed.y < speed.x * -1) {
        model3D->getNode()->setRotation(irr::core::vector3df(0, 0, 0));
    }

    if (tmpPos != _pos && !_moving) {
        model3D->getNode()->setFrameLoop(0, 27);
        _moving = true;
    } else if (tmpPos == _pos && _moving) {
        model3D->getNode()->setFrameLoop(27, 76);
        _moving = false;
    }

    if (boxX == nullptr)
        _pos.x = tmpPos.x;
    if (boxY == nullptr)
        _pos.y = tmpPos.y;
    model3D->setPosition(Engine::Math::Vec3f{_pos.x, 0, _pos.y});
}

const decltype(Game::Entity::Character::_speed) &Game::Entity::Character::getSpeed() const noexcept
{
    return _speed;
}


void Game::Entity::Character::setSpeed(const decltype(_speed) &speed) noexcept
{
    _speed = speed;
}

void Game::Entity::Character::rangeIncrease() noexcept
{
    _range++;
}

void Game::Entity::Character::addBomb() noexcept
{
    _bombStock++;
}
