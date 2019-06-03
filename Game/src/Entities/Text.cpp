/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Text.cpp
*/

#include <memory>

#include "Utils/Colors.hpp"
#include "Entities/Text.hpp"
#include "ECS/Components/Text.hpp"
#include "ECS/Components/Renderer.hpp"

Game::Entity::Text::Text(Engine::ECS::System::Renderer &renderer, const std::wstring &&text, Engine::Math::Vec2<int32_t> pos, const Engine::Utils::Color &color, const std::string &font)
    : AEntity(AEntity::Type::TEXT)
{
    std::shared_ptr<Engine::ECS::IComponent> _text = std::make_shared<Engine::ECS::Component::Text>(renderer, text, pos, color, font);
    addComponent(_text);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>(pos);
    addComponent(_renderer);
}
