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
#include "Utils/Random.hpp"
#include "ECS/Systems/Particle.hpp"

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

    std::dynamic_pointer_cast<Engine::ECS::System::Particle>(Engine::ECS::Manager::getInstance().getSystemByID("Particle"))->
        createParticles(200, Engine::Math::Vec2<float>{4, 6}, Engine::Math::Vec3<float>{200, 0, 150}, Engine::Math::Vec3<float>{200, 0, 0}, 3.5, "Game");
    std::dynamic_pointer_cast<Engine::ECS::System::Particle>(Engine::ECS::Manager::getInstance().getSystemByID("Particle"))->
        createParticles(200, Engine::Math::Vec2<float>{4, 6}, Engine::Math::Vec3<float>{-90, 0, 150}, Engine::Math::Vec3<float>{0, 0, 0}, 3.5, "Game");
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
