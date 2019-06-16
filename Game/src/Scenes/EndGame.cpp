/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EndGame.cpp
*/

#include "ECS/Manager.hpp"
#include "Assets.hpp"
#include "Scenes/EndGame.hpp"
#include "Utils/Color.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Image.hpp"
#include "Entities/Character.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Entities/Button.hpp"
#include "Scenes/GameScene.hpp"

Game::Scene::EndGame::EndGame(bool)
    : AScene{"EndGame", {}, true, true}
{
    auto &manager = Engine::ECS::Manager::getInstance();

    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(manager.getSystemByID("Renderer"))->getVideoDriver();
    auto screenSize = driver->getScreenSize();

    Engine::Abstracts::ASerializable::removeAll();

    _entities = {
            std::make_shared<Engine::Entity::Image>(IMG_BLACK, Engine::Math::Vec2i{0, 0}),
            std::make_shared<Engine::ECS::Entity::Button>(
                    Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60, 400, 90},
                    IMG_NEW_GAME,
                    [&manager]() {
                        while (manager.getScenes().size() != 1)
                            manager.popScene();
                        std::shared_ptr<Engine::Abstracts::AScene> game = std::make_shared<GameScene>();
                        manager.pushScene(game);
                    }),
            std::make_shared<Engine::ECS::Entity::Button>(
                    Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60 * 3, 400, 90},
                    IMG_RESTART_GAME,
                    [&manager]() {
                        while (manager.getScenes().size() != 1)
                            manager.popScene();
                    }
            ),
            std::make_shared<Engine::ECS::Entity::Button>(
                    Engine::Math::Rect_i{static_cast<int>(screenSize.Width - 460), 60 * 5, 400, 90},
                    IMG_EXIT_GAME,
                    []() {
                        auto window = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getWindow();
                        window->closeDevice();
                    }
            )
    };
}

void Game::Scene::EndGame::tick(double)
{}

void Game::Scene::EndGame::sceneShowing()
{}

void Game::Scene::EndGame::sceneHiding(const Engine::Abstracts::AScene *)
{}
