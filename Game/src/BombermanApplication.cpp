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
#include "Scenes/GameScene.hpp"
#include "Assets.hpp"

BombermanApplication::BombermanApplication()
    : Engine::GameApplication(L"Bomberman", 1920, 1080)
{}

void BombermanApplication::onAppStartup()
{
    std::shared_ptr<Engine::Abstracts::AScene> mainMenu = std::make_shared<Game::Scene::MainMenu>();
    Engine::ECS::Manager::getInstance().pushScene(mainMenu);

    std::shared_ptr<Engine::ECS::ISystem> map = std::make_shared<Game::System::Map>();
    Engine::ECS::Manager::getInstance().addSystem(map);

    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(Engine::ECS::Manager::getInstance().getSystemByID("Audio"));
    audio->loadSound("footstep", SND_FOOTSTEP);
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
