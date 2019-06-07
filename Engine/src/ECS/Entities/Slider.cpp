/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Slider.cpp
*/

#include "ECS/Entities/Slider.hpp"
#include "ECS/Components/Slider.hpp"

Game::Entity::Slider::Slider(const Engine::Math::Rect_i &pos, const Engine::Utils::Color &backgroundColor, const Engine::Utils::Color &valueColor)
    : AEntity(AEntity::Type::SLIDER)
{
    std::shared_ptr<Engine::ECS::IComponent> slider = std::make_shared<Engine::ECS::Component::Slider>(pos, backgroundColor, valueColor);
    addComponent(slider);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}

void Game::Entity::Slider::onPressed()
{
    throw std::runtime_error{"Slider Pressed"};
}

void Game::Entity::Slider::onRelease()
{}
