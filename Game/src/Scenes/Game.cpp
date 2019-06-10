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
#include "Entities/Player.hpp"

Game::Scene::Game::Game()
        : AScene("Game", {}, false, false)
{
    _entities = {
            std::make_shared<Entity::Player>(),
            std::make_shared<Entity::Text>(L"Un test", Engine::Math::Vec2i{50, 50}, Engine::Utils::Color{0, 255, 0}),
            std::make_shared<Entity::Button>(Engine::Math::Rect_i{75, 15, 500, 30}, L"Un Button", Engine::Utils::Color{255, 0, 0}),
    };
}

void Game::Scene::Game::tick(double)
{}
