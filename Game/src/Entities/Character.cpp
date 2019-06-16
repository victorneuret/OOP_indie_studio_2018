/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.cpp
*/

#include <cmath>
#include <filesystem>

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
#include "Entities/Powerups/APowerUp.hpp"

decltype(Game::Entity::Character::PLAYER_NB) Game::Entity::Character::PLAYER_NB{0};

Game::Entity::Character::Character(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model)
    : AEntity(AEntity::Type::MODEL3D), _pos{pos}, _speed{30}
{
    PLAYER_NB++;
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
    if (!_alive || _bombStock == 0 || _inBlock)
        return;
    if (_isBombThere(Engine::Math::Vec2i{static_cast<int>(std::round(_pos.x / BLOCK_SIZE) + 1), static_cast<int>(std::round(_pos.z / BLOCK_SIZE) + 1)}))
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

    auto boxX = std::dynamic_pointer_cast<Game::Entity::Block>(map->getBlocks()[static_cast<size_t>(std::round(tmpPos.x / BLOCK_SIZE))][static_cast<size_t>(std::round(_pos.z / BLOCK_SIZE))]);
    auto boxY = std::dynamic_pointer_cast<Game::Entity::Block>(map->getBlocks()[static_cast<size_t>(std::round(_pos.x / BLOCK_SIZE))][static_cast<size_t>(std::round(tmpPos.z / BLOCK_SIZE))]);

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
        auto powerUp = std::dynamic_pointer_cast<Game::Entity::APowerUp>(entity);
        if (bomb != nullptr) {
            auto bombPos = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(bomb->getComponentByID("Model3D"))->getNode()->getPosition();
            if ((static_cast<size_t>(round(bombPos.X / BLOCK_SIZE)) != static_cast<size_t>(round(_pos.x / BLOCK_SIZE)) || static_cast<size_t>(round(bombPos.Z / BLOCK_SIZE)) != static_cast<size_t>(round(_pos.z / BLOCK_SIZE))) && (static_cast<size_t>(round(bombPos.X / BLOCK_SIZE)) == static_cast<size_t>(round(tmpPos.x / BLOCK_SIZE)) && static_cast<size_t>(round(bombPos.Z / BLOCK_SIZE)) == static_cast<size_t>(round(tmpPos.z / BLOCK_SIZE))))
                return;
        }
        if (powerUp == nullptr)
            continue;
        auto powerUpPos = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(powerUp->getComponentByID("Model3D"))->getNode()->getPosition();
        if (static_cast<size_t>(round(powerUpPos.X / BLOCK_SIZE)) == static_cast<size_t>(round(tmpPos.x / BLOCK_SIZE)) && static_cast<size_t>(round(powerUpPos.Z / BLOCK_SIZE)) == static_cast<size_t>(round(tmpPos.z / BLOCK_SIZE))) {
            auto character = std::dynamic_pointer_cast<Game::Entity::Character>(Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntityByID(getID()));
            powerUp->applyEffect(character);
            std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(powerUp->getComponentByID("Model3D"))->getNode()->remove();
            Engine::ECS::Manager::getInstance().getSceneByID("Game")->removeEntityByID(powerUp->getID());
            save();
        }
    }

    bool tmpInBlock = false;

    if (boxX == nullptr || (_ghost && boxX->isBreakable())) {
        if (boxX != nullptr && !_inBlock)
            tmpInBlock = true;
        else if (boxX == nullptr && _inBlock) {
            tmpInBlock = false;
            _ghost = false;
        }
        _pos.x = tmpPos.x;
    }
    if (boxY == nullptr || (_ghost && boxY->isBreakable())) {
        if (boxY != nullptr && !_inBlock)
            tmpInBlock = true;
        else if (boxY == nullptr && _inBlock) {
            tmpInBlock = false;
            _ghost = false;
        }
        _pos.z = tmpPos.z;
    }
    _inBlock = tmpInBlock;
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

void Game::Entity::Character::powerUpAddBomb() noexcept
{
    _maxBombStock++;
    _bombStock++;
}

void Game::Entity::Character::addBomb() noexcept
{
    _bombStock++;
}

void Game::Entity::Character::kill() noexcept
{
    if (!_alive)
        return;

    _alive = false;
    _deathSound.second->play(); // TODO: Adjust volume after merge

    hide();
    save();
}

bool Game::Entity::Character::isAlive() const noexcept
{
    return _alive;
}

const decltype(Game::Entity::Character::_pos) &Game::Entity::Character::getPosition() const
{
    return _pos;
}

void Game::Entity::Character::setGhost(bool isGhost) noexcept
{
    _ghost = isGhost;
}

bool Game::Entity::Character::_isBombThere(const Engine::Math::Vec2i &pos)
{
    for (auto &entity : Engine::ECS::Manager::getInstance().getUpdatedEntities()) {
        auto bomb = std::dynamic_pointer_cast<Game::Entity::Bomb>(entity);

        if (bomb != nullptr) {
            auto bombPos = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(bomb->getComponentByID("Model3D"))->getNode()->getPosition();

            if ((static_cast<size_t>(round(bombPos.X / BLOCK_SIZE)) == static_cast<size_t>(round(pos.x - 1)) && static_cast<size_t>(round(bombPos.Z / BLOCK_SIZE)) == static_cast<size_t>(round(pos.y - 1))))
                return true;
        }
    }
    return false;
}

void Game::Entity::Character::setSuperBomb(bool value) noexcept
{
    _superBomb = value;
}

bool Game::Entity::Character::getSuperBomb() noexcept
{
    return _superBomb;
}

void Game::Entity::Character::load()
{
    const auto file = getFileHandler(".player_" + _playerID + ".save");

    if (file != nullptr)
        file->seekp(0);

    if (file == nullptr || !file->is_open() || file->peek() == std::ifstream::traits_type::eof()) {
        Engine::Logger::getInstance().error("Failed to open player save file");
        return;
    }

    try {
        unpack(*file);
    } catch (const SerializationException &) {
        Engine::Logger::getInstance().error("Failed to load player");
    }
}

void Game::Entity::Character::save() const
{
    const auto file = getFileHandler(".player_" + _playerID + ".save");

    if (file != nullptr && file->is_open()) {
        std::filesystem::resize_file(".player_" + _playerID + ".save", 0);

        file->seekp(0);

        try {
            pack(*file);
        } catch (const SerializationException &) {
            Engine::Logger::getInstance().error("Failed to open player save file");
        }
    } else
        Engine::Logger::getInstance().error("Failed to save player");
}

void Game::Entity::Character::pack(std::ostream &outStream) const
{
    writeAny(outStream, _pos.x);
    writeAny(outStream, _pos.y);
    writeAny(outStream, _pos.z);
    writeAny(outStream, _range);
    writeAny(outStream, _maxBombStock);
    writeAny(outStream, _speed);
    writeAny(outStream, _inBlock);
    writeAny(outStream, _ghost);
    writeAny(outStream, _superBomb);
    writeAny(outStream, _alive);
}

void Game::Entity::Character::unpack(std::istream &inStream)
{
    _pos.x = readAny<decltype(_pos.x)>(inStream);
    _pos.y = readAny<decltype(_pos.y)>(inStream);
    _pos.z = readAny<decltype(_pos.z)>(inStream);
    _range = readAny<decltype(_range)>(inStream);
    _maxBombStock = readAny<decltype(_bombStock)>(inStream);
    _speed = readAny<decltype(_speed)>(inStream);
    _inBlock = readAny<decltype(_inBlock)>(inStream);
    _ghost = readAny<decltype(_ghost)>(inStream);
    _superBomb = readAny<decltype(_superBomb)>(inStream);

    bool alive = readAny<decltype(_alive)>(inStream);

    _bombStock = _maxBombStock;

    if (!alive)
        kill();
}

const decltype(Game::Entity::Character::_playerID) &Game::Entity::Character::getPlayerId() const noexcept
{
    return _playerID;
}
