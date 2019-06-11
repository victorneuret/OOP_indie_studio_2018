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
#include "ECS/Entities/Image.hpp"
#include "ECS/Components/Image.hpp"
#include "ECS/Manager.hpp"
#include "Math/Vector/Vec2.hpp"

Game::Scene::MainMenu::MainMenu()
    : AScene("MainMenu", {}, false, true)
{
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getVideoDriver();

    _entities = {
            std::make_shared<Engine::Entity::Image>("assets/img/star.jpg", Engine::Math::Vec2u{0, 0}),
            std::make_shared<Engine::Entity::Image>("assets/img/sun.png", Engine::Math::Vec2u{driver->getScreenSize().Width / 2 - (894 / 2), 0}),
            std::make_shared<Engine::Entity::Image>("assets/img/mountain.png", Engine::Math::Vec2u{0, 0})
    };

    for (auto image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(image->getComponentByID("Image"));
            if (imgComponent == nullptr)
                continue;
            if (imgComponent->getTexturePath() == "assets/img/sun.png")
                imgComponent->getGUIImage()->setScaleImage(true);
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
    for (auto image : _entities) {
        if (image->getType() == Engine::ECS::IEntity::Type::MODEL2D) {
            auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(image->getComponentByID("Image"));
            if (imgComponent == nullptr)
                continue;
            if (imgComponent->getTexturePath() == "assets/img/sun.png") {
                imgComponent->setSize(Engine::Math::Vec2u{size, size});
                imgComponent->setPosition(Engine::Math::Vec2u{driver->getScreenSize().Width / 2 - (size / 2), 0});
            }
        }
    }
}
