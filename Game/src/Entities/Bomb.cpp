/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Bomb.cpp
*/

#include "Entities/Character.hpp"
#include "Systems/Map.hpp"
#include "ECS/Manager.hpp"
#include "Systems/Map.hpp"
#include "Entities/Bomb.hpp"
#include "Math/Vector/Vec3.hpp"
#include "ECS/Components/Timer.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Systems/Audio.hpp"

Game::Entity::Bomb::Bomb(const decltype(_playerID) &playerID, const decltype(_pos) &pos, const decltype(_range) &range)
    : AEntity{AEntity::Type::MODEL3D}, _pos{pos}, _range{range}, _playerID{playerID}
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(Engine::Math::Vec3f{static_cast<float>(INDEX_TO_POS(_pos.x - 1)), 0, static_cast<float>(INDEX_TO_POS(_pos.y - 1) - 1)}, "assets/models/bomb/Bomb.obj");
    addComponent(_3DModel);
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(getComponentByID("Model3D"))->addTexture("assets/models/bomb/Bomb.png");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(getComponentByID("Model3D"))->setScale(Engine::Math::Vec3f{1.5, 1.5, 1.5});

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);

    std::function<void()> lambda{[this]() { this->onExplode(); }};
    std::shared_ptr<Engine::ECS::IComponent> timer = std::make_shared<Engine::ECS::Component::Timer>(2.0, lambda);
    addComponent(timer);
}

void Game::Entity::Bomb::onExplode()
{
    auto &manager = Engine::ECS::Manager::getInstance();
    auto mapSystem = std::dynamic_pointer_cast<Game::System::Map>(manager.getSystemByID("Map"));
    auto map = mapSystem->getActualMap();

    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D> (Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntityByID(getID())->getComponentByID("Model3D"))->getNode()->remove();
    Engine::ECS::Manager::getInstance().getSceneByID("Game")->removeEntityByID(getID());

    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(manager.getSystemByID("Audio"));

    auto sound = audio->getSound("bomb_explode");
    sound.second->play();

    for (size_t i = 0; i <= _range && _pos.x + i < MAP_WIDTH + 1; i++) {
        if (map[_pos.x + i - 1][_pos.y - 1] != '0') {
            mapSystem->removeBlock(Engine::Math::Vec2i{_pos.x + static_cast<int>(i), _pos.y});
            break;
        }
    }

    for (size_t i = 0; i <= _range && _pos.x - i > 0; i++) {
        if (map[_pos.x - i - 1][_pos.y - 1] != '0') {
            mapSystem->removeBlock(Engine::Math::Vec2i{_pos.x - static_cast<int>(i), _pos.y});
            break;
        }
    }

    for (size_t i = 0; i <= _range && _pos.y + i < MAP_HEIGHT + 1; i++) {
        if (map[_pos.x - 1][_pos.y + i - 1] != '0') {
            mapSystem->removeBlock(Engine::Math::Vec2i{_pos.x, _pos.y + static_cast<int>(i)});
            break;
        }
    }

    for (size_t i = 0; i <= _range && _pos.y - i > 0; i++) {
        if (map[_pos.x - 1][_pos.y - i - 1] != '0') {
            mapSystem->removeBlock(Engine::Math::Vec2i{_pos.x, _pos.y - static_cast<int>(i)});
            break;
        }
    }
    std::dynamic_pointer_cast<Game::Entity::Character>(Engine::ECS::Manager::getInstance().getSceneByID("Game")->getEntityByID(_playerID))->addBomb();
}

const decltype(Game::Entity::Bomb::_pos) &Game::Entity::Bomb::getPos() const noexcept
{
    return _pos;
}
