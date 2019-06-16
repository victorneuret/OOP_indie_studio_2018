/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SuperBomb.cpp
*/

#include "Entities/Powerups/SuperBomb.hpp"

Game::Entity::SuperBomb::SuperBomb(const Engine::Math::Vec3f &pos, const std::string &model)
{
    std::shared_ptr<Engine::ECS::IComponent> model3D = std::make_shared<Engine::ECS::Component::Model3D>(pos, model);
    addComponent(model3D);

    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(model3D)->addTexture("assets/img/superbomb.png");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(model3D)->setScale(Engine::Math::Vec3f{5, 5, 5});

    std::shared_ptr<Engine::ECS::IComponent> renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(renderer);
}

void Game::Entity::SuperBomb::applyEffect(std::shared_ptr<Game::Entity::Character> &player)
{
    player->setSuperBomb(true);
}