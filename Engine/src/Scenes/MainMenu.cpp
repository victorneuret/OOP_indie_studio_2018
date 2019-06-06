/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.cpp
*/

#include "Scenes/MainMenu.hpp"
#include "ECS/Components/Button.hpp"
#include "ECS/Manager.hpp"

Engine::Scene::MainMenu::MainMenu(decltype(_entities) &entities)
    : AScene("MainMenu", entities, false, true)
{}

void Engine::Scene::MainMenu::tick(double)
{}