/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombermanApplication.cpp
*/

#include <memory>

#include "BombermanApplication.hpp"
#include "ECS/Manager.hpp"
#include "Systems/Map.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/Game.hpp"

BombermanApplication::BombermanApplication()
    : Engine::GameApplication(L"Bomberman", 1920, 1080)
{
}

void BombermanApplication::onAppStartup()
{
    std::shared_ptr<Engine::Abstracts::AScene> mainMenu = std::make_shared<Game::Scene::MainMenu>();
    Engine::ECS::Manager::getInstance().pushScene(mainMenu);

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
