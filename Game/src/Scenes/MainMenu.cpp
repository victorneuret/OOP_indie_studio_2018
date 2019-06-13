/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.cpp
*/

#include <iostream>
#include <memory>

#include "Scenes/MainMenu.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "Entities/Block.hpp"
#include "Entities/Player.hpp"
#include "ECS/Entities/Image.hpp"
#include "ECS/Components/Image.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Math/Vector/Vec2.hpp"
#include "Math/Rect.hpp"
#include "Scenes/Game.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "Systems/Map.hpp"

Game::Scene::MainMenu::MainMenu()
    : AScene{"MainMenu", {}, true, true}, _music{}
{
    auto &manager = Engine::ECS::Manager::getInstance();

    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(manager.getSystemByID("Renderer"))->getVideoDriver();
    auto screenSize = driver->getScreenSize();

    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(manager.getSystemByID("Audio"));
    auto sound = audio->loadSound("main_music", "assets/musics/ignite.ogg");

    _music = sound.second;
    _music->setLoop(true);
    _music->play();

    _audioVisualizer = std::make_unique<AudioVisualizer>(*sound.second, *sound.first);

    _entities = {
        std::make_shared<Engine::Entity::Image>("assets/img/star.jpg", Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>("assets/img/sun.png", Engine::Math::Vec2i{static_cast<int>(screenSize.Width / 2 - (894 / 2)), 0}),
        std::make_shared<Engine::Entity::Image>("assets/img/mountain.png", Engine::Math::Vec2i{0, 0}),
        std::make_shared<Engine::Entity::Image>("assets/img/cuteBomber.png", Engine::Math::Vec2i{0, 50}),

        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60, 400, 90},
            "assets/img/newGame.png",
            []() {
                std::shared_ptr<Engine::Abstracts::AScene> game = std::make_shared<Game>();
                Engine::ECS::Manager::getInstance().addScene(game);
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60 * 3, 400, 90},
            "assets/img/pink.png",
            []() {
                std::cout << "Load Game" << std::endl;
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60 * 5, 400, 90},
            "assets/img/pink.png",
            []() {
                auto window = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getWindow();
                window->closeDevice();
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

Game::Scene::MainMenu::~MainMenu()
{
    auto &manager = Engine::ECS::Manager::getInstance();
    auto audio = std::dynamic_pointer_cast<Engine::ECS::System::Audio>(manager.getSystemByID("Audio"));

    _music->stop();
    audio->unloadSound("main_music");
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
