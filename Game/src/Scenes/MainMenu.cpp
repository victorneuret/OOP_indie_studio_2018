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
    _entities = {};
}

void Game::Scene::MainMenu::tick(double)
{}
