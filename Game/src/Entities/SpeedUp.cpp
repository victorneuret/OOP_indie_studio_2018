/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "Entities/Character.hpp"
#include "Entities/SpeedUp.hpp"

Game::Entity::SpeedUp::SpeedUp(const Engine::Math::Vec3f &pos, const std::string &model)
{
    std::shared_ptr<Engine::ECS::IComponent> model3D = std::make_shared<Engine::ECS::Component::Model3D>(pos, model);
    addComponent(model3D);

    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(model3D)->addTexture("assets/img/speedup.png");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(model3D)->setScale(Engine::Math::Vec3f{5, 5, 5});

    std::shared_ptr<Engine::ECS::IComponent> renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(renderer);
}

void Game::Entity::SpeedUp::applyEffect(std::shared_ptr<Game::Entity::Character> &player)
{
    player->setSpeed(player->getSpeed() * 1.12);
}
