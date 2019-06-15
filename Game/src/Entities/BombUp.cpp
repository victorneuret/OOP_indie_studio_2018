/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombUp.cpp
*/

#include "Entities/Character.hpp"
#include "Entities/BombUp.hpp"

Game::Entity::BombUp::BombUp(const Engine::Math::Vec3f &pos, const std::string &model)
{
    std::shared_ptr<Engine::ECS::IComponent> _3DModel = std::make_shared<Engine::ECS::Component::Model3D>(pos, model);
    addComponent(_3DModel);

    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->addTexture("assets/img/bombup.png");
    std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(_3DModel)->setScale(Engine::Math::Vec3f{5, 5, 5});

    std::shared_ptr<Engine::ECS::IComponent> _Renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_Renderer);
}

void Game::Entity::BombUp::applyEffect(std::shared_ptr<Game::Entity::Character> &player)
{
    player->addBomb();
}
