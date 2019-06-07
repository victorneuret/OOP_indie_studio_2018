/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.cpp
*/

#include "ECS/Entities/Button.hpp"
#include "ECS/Components/Button.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Interfaces/IEntity.hpp"

Game::Entity::Button::Button(const Engine::Math::Rect_i &pos, const std::wstring &text)
    : AEntity(AEntity::Type::BUTTON)
{
    std::shared_ptr<Engine::ECS::IComponent> button = std::make_shared<Engine::ECS::Component::Button>(pos, text);
    addComponent(button);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}
