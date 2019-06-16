/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PauseMenu.cpp
*/

#include "Scenes/PauseMenu.hpp"
#include "ECS/Entities/Image.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "ECS/Manager.hpp"
#include "ECS/Entities/Button.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Components/Image.hpp"
#include "Systems/Map.hpp"
#include "Assets.hpp"
#include "Utils/Color.hpp"

Game::Scene::PauseMenu::PauseMenu()
    : AScene("PauseMenu", {}, true, true)
{
    auto &manager = Engine::ECS::Manager::getInstance();
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(manager.getSystemByID("Renderer"))->getVideoDriver();
    auto screenSize = driver->getScreenSize();

    renderer->getSceneManager()->setActiveCamera(renderer->getSceneManager()->addCameraSceneNode(nullptr, irr::core::vector3df(0, 0, 0), irr::core::vector3df(0, 0 ,0)));

    _entities = {
        std::make_shared<Engine::Entity::Image>("assets/img/black-low-opacity.png", Engine::Math::Vec2i{0, 0}),

        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width / 2 - 200), static_cast<int>(screenSize.Height / 2), 400, 90},
            "assets/img/play.png",
            [renderer]() {
                renderer->getSceneManager()->setActiveCamera(renderer->getSceneManager()->addCameraSceneNode(
                    nullptr,
                    irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 125,
                                         INDEX_TO_POS(static_cast<float>(MAP_HEIGHT - 1))),
                    irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 0,
                                         INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)))));
                Engine::ECS::Manager::getInstance().popScene();
            }
        ),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(screenSize.Width / 2 - 200), static_cast<int>(screenSize.Height / 2 + 120), 400, 90},
            "assets/img/quit.png",
            []() {
                auto window = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getWindow();
                window->closeDevice();
            }
        ),
    };
}

void Game::Scene::PauseMenu::tick(double)
{
    auto input = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));

    if (input->isKeyDown(irr::EKEY_CODE::KEY_ESCAPE)) {
        if (!_pauseLock) {
            _pauseLock = true;
            auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));
            renderer->getSceneManager()->setActiveCamera(renderer->getSceneManager()->addCameraSceneNode(
                nullptr,
                irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 125,
                                     INDEX_TO_POS(static_cast<float>(MAP_HEIGHT - 1))),
                irr::core::vector3df(INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)), 0,
                                     INDEX_TO_POS(static_cast<float>((MAP_WIDTH - 1) / 2.f)))));
            Engine::ECS::Manager::getInstance().popScene();
        }
    } else {
        _pauseLock = false;
    }
}

void Game::Scene::PauseMenu::sceneShowing()
{
}

void Game::Scene::PauseMenu::sceneHiding(const Engine::Abstracts::AScene *)
{
}
