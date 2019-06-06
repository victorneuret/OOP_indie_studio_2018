/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.cpp
*/

#include <Entities/Button.hpp>
#include "Scenes/MainMenu.hpp"
#include "ECS/Components/Button.hpp"
#include "ECS/Engine.hpp"

Engine::Scene::MainMenu::MainMenu()
    : AScene("MainMenu", {}, false, true)
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Engine::getInstance().getSystemByID("Renderer"));

    _entities = {
        std::make_shared<Game::Entity::Button>(*renderer, Math::Rect_i{75, 15, 500, 30}, L"Un Button")
    };
}

void Engine::Scene::MainMenu::tick(double deltaTime)
{
    
}