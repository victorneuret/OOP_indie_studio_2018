/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Text.cpp
*/

#include <memory>

#include "Utils/Colors.hpp"
#include "Entities/Text.hpp"
#include "ECS/Components/Renderer.hpp"

Game::Entity::Text::Text(Engine::ECS::System::Renderer &renderer, const decltype(Game::Entity::Text::_text) &&text, Engine::Math::Vec2<int32_t> pos, const Engine::Utils::Color &color, const std::string &font)
{
    std::shared_ptr<Engine::ECS::IComponent> component = std::make_shared<Engine::ECS::Component::Renderer>(renderer, text, pos, color, font);
    addComponent(component);
}
