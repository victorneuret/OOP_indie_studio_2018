/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.cpp
*/

#include "Scenes/MainMenu.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "Entities/Block.hpp"
#include "Entities/Player.hpp"

Game::Scene::MainMenu::MainMenu()
    : AScene("MainMenu", {}, false, true)
{
    _entities = {
        std::make_shared<Game::Entity::Player>(),
        std::make_shared<Game::Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0}),
        std::make_shared<Game::Entity::Button>(Engine::Math::Rect_i{75, 15, 500, 30}, L"Un Button", Engine::Utils::Color{255, 0, 0}),
    };
}

void Game::Scene::MainMenu::tick(double)
{}