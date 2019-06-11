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
#include "Systems/Particle.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/Game.hpp"

BombermanApplication::BombermanApplication()
    : Engine::GameApplication(L"Bomberman", 1920, 1080)
{
}

void BombermanApplication::onAppStartup()
{
    std::shared_ptr<Engine::Abstracts::AScene> mainMenu = std::make_shared<Game::Scene::MainMenu>();
    std::shared_ptr<Engine::Abstracts::AScene> game = std::make_shared<Game::Scene::Game>();
    Engine::ECS::Manager::getInstance().addScene(mainMenu);
    Engine::ECS::Manager::getInstance().addScene(game);

    std::shared_ptr<Engine::ECS::ISystem> map = std::make_shared<Game::System::Map>();
    Engine::ECS::Manager::getInstance().addSystem(map);

    std::shared_ptr<Engine::ECS::ISystem> particles = std::make_shared<Game::System::Particle>();
    Engine::ECS::Manager::getInstance().addSystem(particles);

    std::dynamic_pointer_cast<Game::System::Particle>(particles)->createParticles(1, Engine::Math::Vec2<int>{2, 3}, Engine::Math::Vec3<float>{10, 0, 10}, Engine::Math::Vec3<float>{30, 5, 20}, 5);
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
