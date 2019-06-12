/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.cpp
*/

#include <iostream>

#include "Scenes/MainMenu.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "Entities/Block.hpp"
#include "Entities/Player.hpp"
#include "ECS/Entities/Image.hpp"
#include "ECS/Components/Image.hpp"
#include "ECS/Manager.hpp"
#include "Math/Vector/Vec2.hpp"
#include "Math/Rect.hpp"

Game::Scene::MainMenu::MainMenu()
    : AScene{"MainMenu", {}, false, true}
{
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();
    auto screenSize = driver->getScreenSize();

    _entities = {
        std::make_shared<Engine::Entity::Image>("assets/img/star.jpg", Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>("assets/img/sun.png", Engine::Math::Vec2i{static_cast<int>(screenSize.Width / 2 - (894 / 2)), 0}),
        std::make_shared<Engine::Entity::Image>("assets/img/mountain.png", Engine::Math::Vec2i{0, 0}),

        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{
                static_cast<int>(screenSize.Width * 0.06),
                static_cast<int>(screenSize.Height - 100),
                static_cast<int>(screenSize.Width * 0.25),
                30
            },
            L"New Game",
            []() {
                std::cout << "New Game" << std::endl;
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{
                static_cast<int>(screenSize.Width * 0.06 * 2 + (screenSize.Width * 0.25)),
                static_cast<int>(screenSize.Height - 100),
                static_cast<int>(screenSize.Width * 0.25),
                30
            },
            L"Load Game",
            []() {
                std::cout << "Load Game" << std::endl;
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{
                static_cast<int>(screenSize.Width * 0.06 * 3 + (screenSize.Width * 0.25 * 2)),
                static_cast<int>(screenSize.Height - 100),
                static_cast<int>(screenSize.Width * 0.25),
                30
            },
            L"Quit",
            []() {
                std::cout << "Quit" << std::endl;
            }
        )
    };

    for (auto &image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(image->getComponentByID("Image"));
            if (imgComponent == nullptr)
                continue;
            if (imgComponent->getTexturePath() == "assets/img/sun.png")
                imgComponent->getGUIImage()->setScaleImage(true);
            else if (imgComponent->getTexturePath() == "assets/img/mountain.png")
                imgComponent->setPosition(Engine::Math::Vec2i{0, static_cast<int>(imgComponent->getSize().y - driver->getScreenSize().Height)});
        }
    }
}

void Game::Scene::MainMenu::tick(double dt)
{
    static unsigned int size = 800;

    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();

    if (size <= 400)
        size = 800;
    size -= 1 * dt;
    for (auto &image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(image->getComponentByID("Image"));
            if (imgComponent == nullptr)
                continue;
            if (imgComponent->getTexturePath() == "assets/img/sun.png") {
                imgComponent->setSize(Engine::Math::Vec2u{size, size});
                imgComponent->setPosition(Engine::Math::Vec2i{static_cast<int>(driver->getScreenSize().Width / 2 - (size / 2)), 0});
            }
        }
    }
}
