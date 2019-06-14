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
#include "ECS/Components/Image.hpp"

Game::Scene::PauseMenu::PauseMenu()
    : AScene("PauseMenu", {}, false, false)
{
    _entities = {
        std::make_shared<Engine::Entity::Image>("assets/img/pauseMenu.png", Engine::Math::Vec2i{0, 0})
    };
    auto imgComponent = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(_entities.front()->getComponentByID("Image"));
    imgComponent->getGUIImage()->setScaleImage(true);
    imgComponent->setSize(Engine::Math::Vec2u{400, 800});
}

void Game::Scene::PauseMenu::tick(double)
{
    auto input = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));

    if (input->isKeyDown(irr::EKEY_CODE::KEY_ESCAPE)) {
        try {
            auto toDelete = Engine::ECS::Manager::getInstance().getSceneByID("PauseMenu");
            Engine::ECS::Manager::getInstance().getSceneByID("Game")->updateChild(true);
            Engine::ECS::Manager::getInstance().removeScene(toDelete);
        } catch (const ECSException<ECS_Scene> &) {}
    }
}