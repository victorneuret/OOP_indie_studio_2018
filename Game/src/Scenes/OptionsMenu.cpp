/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** OptionsMenu.cpp
*/

#include "Scenes/OptionsMenu.hpp"

#include "ECS/Entities/Button.hpp"
#include "ECS/Manager.hpp"

Game::Scene::OptionsMenu::OptionsMenu()
    : AScene("OptionsMenu", {}, false, true)
{
    auto &manager = Engine::ECS::Manager::getInstance();
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(manager.getSystemByID("Renderer"))->getVideoDriver();
    auto screenSize = driver->getScreenSize();

    _entities = {
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width / 2 - 200), static_cast<int>(screenSize.Height / 2 + 120), 400, 90},
            "assets/img/pink.png",
            []() {
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width / 2 - 200), static_cast<int>(screenSize.Height / 2 + 240), 400, 90},
            "assets/img/quit.png",
            []() {
                Engine::ECS::Manager::getInstance().popScene();
            }
        ),
    };
}

void Game::Scene::OptionsMenu::tick(double)
{}

void Game::Scene::OptionsMenu::sceneShowing()
{}

void Game::Scene::OptionsMenu::sceneHiding(const Engine::Abstracts::AScene *)
{}
