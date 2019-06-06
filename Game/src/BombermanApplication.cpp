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
#include "Scenes/MainMenu.hpp"

BombermanApplication::BombermanApplication()
    : Engine::GameApplication(L"Bomberman", 1920, 1080)
{
}

void BombermanApplication::onAppStartup()
{
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> mainMenuEntities = {
        std::make_shared<Game::Entity::Player>(),
        std::make_shared<Game::Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0}),
        std::make_shared<Game::Entity::Button>(Engine::Math::Rect_i{75, 15, 500, 30}, L"Un Button"),
    };
    std::shared_ptr<Engine::Scene::AScene> mainMenu = std::make_shared<Engine::Scene::MainMenu>(mainMenuEntities);
    Engine::ECS::Manager::getInstance().addScene(mainMenu);

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
