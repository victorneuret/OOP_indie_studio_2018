/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Game.cpp
*/


#include "Scenes/Game.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "Entities/Block.hpp"
#include "ECS/Entities/Image.hpp"
#include "Entities/Player.hpp"
#include "ECS/Manager.hpp"
#include "Entities/Bomb.hpp"
#include "Systems/Map.hpp"

Game::Scene::Game::Game()
        : AScene("Game", {}, false, false)
{
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();

    _entities = {
            std::make_shared<Entity::Player>(),
            std::make_shared<Engine::ECS::Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0}),
            std::make_shared<Engine::ECS::Entity::Button>(Engine::Math::Rect_i{75, 15, 500, 30}, L"Un Button", Engine::Utils::Color{255, 0, 0}),
            std::make_shared<Engine::Entity::Image>("assets/img/sun.png", Engine::Math::Vec2u{driver->getScreenSize().Width / 2 - (894 / 2), 0}),
            std::make_shared<Entity::Bomb>(Engine::Math::Vec2i{MAP_WIDTH - 1, MAP_HEIGHT}),
    };
}

void Game::Scene::Game::tick(double)
{}
