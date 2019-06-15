/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.cpp
*/

#include <cmath>

#include "Assets.hpp"
#include "Entities/Character.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Systems/Particle.hpp"
#include "Systems/Map.hpp"
#include "ECS/Manager.hpp"
#include "Entities/Bomb.hpp"
#include "Entities/Block.hpp"
#include "ECS/Systems/Audio.hpp"

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

    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(Engine::ECS::Manager::getInstance().getSystemByID("Audio"));
    _stepSound = audio->getSound("footstep");
    _stepSound.second->setVolume(70);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);

    _deathSound = audio->isLoaded("death_sound") ? audio->getSound("death_sound") : audio->loadSound("death_sound", SND_DEATH);
}

void Game::Entity::Character::placeBomb() noexcept
{
    if (!_alive || _bombStock == 0)
        return;
    auto entities = Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntities();

    std::shared_ptr<Engine::ECS::IEntity> bomb = std::make_shared<Game::Entity::Bomb>(getID(), Engine::Math::Vec2i{static_cast<int>(std::round(_pos.x / BLOCK_SIZE) + 1), static_cast<int>(std::round(_pos.z / BLOCK_SIZE) + 1)}, _range);
    Engine::ECS::Manager::getInstance().getSceneByID("Game")->addEntity(bomb);
    _bombStock--;
}

void Game::Entity::Character::move(const Engine::Math::Vec2f &speed, float timeMove) noexcept
{
    if (!_alive)
        return;

    auto model3D = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(getComponentByID("Model3D"));
    decltype(_pos) tmpPos{_pos};
    _time += timeMove;

    if (model3D == nullptr)
        return;

    tmpPos.x += speed.x * _speed * timeMove;
    tmpPos.z += speed.y * _speed * timeMove;

    if (tmpPos.x < 0)
        tmpPos.x = 0;
    else if (tmpPos.x + INDEX_TO_POS(1) > INDEX_TO_POS(MAP_WIDTH))
        tmpPos.x = INDEX_TO_POS(MAP_WIDTH - 1);
    if (tmpPos.z < 0)
        tmpPos.z = 0;
    else if (tmpPos.z + INDEX_TO_POS(1) > INDEX_TO_POS(MAP_HEIGHT))
        tmpPos.z = INDEX_TO_POS(MAP_HEIGHT - 1);

    auto map = std::dynamic_pointer_cast<Game::System::Map>(Engine::ECS::Manager::getInstance().getSystemByID("Map"));

    if (map == nullptr || map->getActualMap().empty())
        return;

    auto boxX = map->getBlocks()[static_cast<size_t>(std::round(tmpPos.x / BLOCK_SIZE))][static_cast<size_t>(std::round(_pos.z / BLOCK_SIZE))];
    auto boxY = map->getBlocks()[static_cast<size_t>(std::round(_pos.x / BLOCK_SIZE))][static_cast<size_t>(std::round(tmpPos.z / BLOCK_SIZE))];

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

    if (_moving && _time >= 0.35) {
        _stepSound.second->play();
        _time -= 0.35;
    } else if (!_moving && _time >= 0.35 * 2){
        _time = -0.35;
    }

    for (auto &entity : Engine::ECS::Manager::getInstance().getUpdatedEntities()) {
        auto bomb = std::dynamic_pointer_cast<Game::Entity::Bomb>(entity);
        if (bomb == nullptr)
            continue;
        auto bombPos = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(bomb->getComponentByID("Model3D"))->getNode()->getPosition();
        if (static_cast<size_t>(std::round(bombPos.X / BLOCK_SIZE)) == static_cast<size_t>(std::round(_pos.x / BLOCK_SIZE)) && static_cast<size_t>(std::round(bombPos.Z / BLOCK_SIZE)) == static_cast<size_t>(std::round(_pos.z / BLOCK_SIZE)))
            continue;
        if (static_cast<size_t>(std::round(bombPos.X / BLOCK_SIZE)) == static_cast<size_t>(std::round(tmpPos.x / BLOCK_SIZE)) && static_cast<size_t>(std::round(bombPos.Z / BLOCK_SIZE)) == static_cast<size_t>(std::round(tmpPos.z / BLOCK_SIZE)))
            return;
    }

    if (boxX == nullptr)
        _pos.x = tmpPos.x;
    if (boxY == nullptr)
        _pos.z = tmpPos.z;
    model3D->setPosition(Engine::Math::Vec3f{_pos.x, 0, _pos.z});
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

void Game::Entity::Character::kill() noexcept
{
    _alive = false;
    _deathSound.second->play(); // TODO: Adjust volume after merge

    hide();
}

bool Game::Entity::Character::isAlive() const noexcept
{
    return _alive;
}

const decltype(Game::Entity::Character::_pos) &Game::Entity::Character::getPosition() const
{
    return _pos;
}
