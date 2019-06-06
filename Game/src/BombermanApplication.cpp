/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombermanApplication.cpp
*/

#include "Math/Rect.hpp"
#include "Utils/Logger.hpp"
#include "BombermanApplication.hpp"

#include "ECS/Manager.hpp"
#include "Systems/Map.hpp"
#include "Entities/Text.hpp"
#include "Entities/Block.hpp"
#include "Entities/Button.hpp"
#include "Entities/Player.hpp"

BombermanApplication::BombermanApplication()
    : Engine::GameApplication(L"Bomberman", 1920, 1080)
{
}

void BombermanApplication::onAppStartup()
{
    std::shared_ptr<Engine::ECS::IEntity> entity1 = std::make_shared<Game::Entity::Player>();
    Engine::ECS::Manager::getInstance().addEntity(entity1);
    std::shared_ptr<Engine::ECS::IEntity> entity3 = std::make_shared<Game::Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0});
    Engine::ECS::Manager::getInstance().addEntity(entity3);
    std::shared_ptr<Engine::ECS::IEntity> entity4 = std::make_shared<Game::Entity::Button>(Engine::Math::Rect_i{75, 15, 500, 30}, L"Un Button");
    Engine::ECS::Manager::getInstance().addEntity(entity4);
    std::shared_ptr<Engine::ECS::ISystem> map = std::make_shared<Game::System::Map>();
    Engine::ECS::Manager::getInstance().addSystem(map);
}

void BombermanApplication::tick(double)
{
}

void BombermanApplication::onAppShutdown()
{
}

void BombermanApplication::onAppCrash()
{
}
