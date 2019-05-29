/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include <memory>

#include "Entities/Player.hpp"
#include "ECS/Components/Renderer.hpp"

Game::Entity::Player::Player(Engine::ECS::System::Renderer &renderer, const std::string &model, const std::string &texture)
{
    std::shared_ptr<Engine::ECS::IComponent> component = std::make_shared<Engine::ECS::Component::Renderer>(renderer, model, texture, Engine::ECS::Component::Renderer::type::MODEL3D);
    addComponent(component);
}
