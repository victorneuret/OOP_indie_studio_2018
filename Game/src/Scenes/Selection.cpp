/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Selection.cpp
*/

#include <memory>
#include <vector>

#include "ECS/Manager.hpp"
#include "Scenes/Selection.hpp"
#include "Entities/Player.hpp"
#include "ECS/Entities/Button.hpp"

Game::Scene::Selection::Selection()
    : AScene{"Selection", {}, false, true}
{
    auto &manager = Engine::ECS::Manager::getInstance();
    const auto camera = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(
        Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getSceneManager()->getActiveCamera();
    auto pos = camera->getTarget();
    auto driver = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(manager.getSystemByID("Renderer"))->getVideoDriver();
    auto screenSize = driver->getScreenSize();

    pos.Y += 20;

    _entities = {
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{pos.X, pos.Y, pos.Z}, "assets/models/characters/BlackBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{pos.X, pos.Y, pos.Z}, "assets/models/characters/PinkBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{pos.X, pos.Y, pos.Z}, "assets/models/characters/RedBombermanTextures.png"),
        std::make_shared<Entity::Player>(Engine::Math::Vec3f{pos.X, pos.Y, pos.Z}, "assets/models/characters/WhiteBombermanTextures.png"),
        std::make_shared<Engine::ECS::Entity::Button>(
            Engine::Math::Rect_i{static_cast<int>(pos.X) + screenSize.Width / 8,
                                 static_cast<int>(pos.Y) + screenSize.Height / 4 * 3, 400, 90},
            "assets/img/newGame.png",
            []() {}
        ),
    };

    for (uint8_t i = 0; i < _entities.size(); i++) {
        if (_entities[i]->getType() == Engine::ECS::IEntity::Type::MODEL3D) {
            auto model3D = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_entities[i]->getComponentByID("Model3D"));
            auto newPos = model3D->getNode()->getPosition();
            const auto size = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(
                Engine::ECS::Manager::getInstance().getSystemByID("Renderer"))->getWindow()->getVideoDriver()->getScreenSize();

            newPos.X = (static_cast<float>(size.Width)  / 32) * i - (static_cast<float>(size.Width) / 128);

            model3D->setScale({30, 30, 30});
            model3D->setRotation({20, 180, 0});
            model3D->setPosition({newPos.X, newPos.Y, newPos.Z});
        }
    }
}

void Game::Scene::Selection::tick(double dt)
{
    for (auto &entity : _entities) {
        if (entity->getType() == Engine::ECS::IEntity::Type::MODEL3D) {
            auto model3D = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(entity->getComponentByID("Model3D"));
            auto rotation = model3D->getNode()->getRotation();

            rotation.Y += 20.f * dt;

            model3D->setRotation({rotation.X, rotation.Y, rotation.Z});
        }
    }
}

void Game::Scene::Selection::sceneShowing()
{}

void Game::Scene::Selection::sceneHiding(const AScene *newParent)
{}
