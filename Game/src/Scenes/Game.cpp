/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Game.cpp
*/

#include <iostream>
#include <ECS/Systems/Input/KeyboardInput.hpp>

#include "Scenes/Game.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "Entities/Block.hpp"
#include "Entities/Player.hpp"
#include "ECS/Entities/Image.hpp"
#include "Entities/Player.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Particle.hpp"
#include "Entities/Bomb.hpp"
#include "Systems/Map.hpp"

Game::Scene::Game::Game()
        : AScene("Game", {}, true, true)
{
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();

    _entities = {
        std::make_shared<Engine::Entity::Image>("assets/img/city.png", Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>("assets/img/sun.png", Engine::Math::Vec2i{static_cast<int>(driver->getScreenSize().Width / 2 - (894 / 2)), -200}),
        std::make_shared<Engine::ECS::Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0}),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(0), 0, INDEX_TO_POS(0)}, "assets/models/characters/BlackBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(0), 0, INDEX_TO_POS(MAP_WIDTH - 1)}, "assets/models/characters/PinkBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(MAP_HEIGHT - 1), 0, INDEX_TO_POS(0)}, "assets/models/characters/RedBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{INDEX_TO_POS(MAP_HEIGHT - 1), 0, INDEX_TO_POS(MAP_WIDTH - 1)}, "assets/models/characters/WhiteBombermanTextures.png"),
    };
}

void Game::Scene::Game::tick(double dt)
{
    std::dynamic_pointer_cast<Engine::ECS::System::Particle>(Engine::ECS::Manager::getInstance().getSystemByID("Particle"))->
        createParticles(1, Engine::Math::Vec2<float>{4, 6}, Engine::Math::Vec3<float>{200, 0, 150}, Engine::Math::Vec3<float>{200, 0, 0}, 3.5, "Game");
    std::dynamic_pointer_cast<Engine::ECS::System::Particle>(Engine::ECS::Manager::getInstance().getSystemByID("Particle"))->
        createParticles(1, Engine::Math::Vec2<float>{4, 6}, Engine::Math::Vec3<float>{-90, 0, 150}, Engine::Math::Vec3<float>{0, 0, 0}, 3.5, "Game");
    constexpr float speed = 42.42;
    auto inputs = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));
    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_RIGHT))
        for (auto &entity : _entities) {
            auto entityBackup = std::dynamic_pointer_cast<Entity::Character>(entity);
            if (entityBackup != nullptr) {
                entityBackup->move({speed * -1, 0 * speed}, dt);
                break;
            }
        }

    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_LEFT))
        for (auto &entity : _entities) {
            auto entityBackup = std::dynamic_pointer_cast<Entity::Character>(entity);
            if (entityBackup != nullptr) {
                entityBackup->move({1 * speed, 0 * speed}, dt);
                break;
            }
        }

    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_UP))
        for (auto &entity : _entities) {
            auto entityBackup = std::dynamic_pointer_cast<Entity::Character>(entity);
            if (entityBackup != nullptr) {
                entityBackup->move({0 * speed, -1 * speed}, dt);
                break;
            }
        }

    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_DOWN))
        for (auto &entity : _entities) {
            auto entityBackup = std::dynamic_pointer_cast<Entity::Character>(entity);
            if (entityBackup != nullptr) {
                entityBackup->move({0 * speed, 1 * speed}, dt);
                break;
            }
        }

    if (inputs->isKeyDown(irr::EKEY_CODE::KEY_SPACE))
        for (auto &entity : _entities) {
            auto entityBackup = std::dynamic_pointer_cast<Entity::Character>(entity);
            if (entityBackup != nullptr) {
                entityBackup->placeBomb();
                break;
            }
        }
}
