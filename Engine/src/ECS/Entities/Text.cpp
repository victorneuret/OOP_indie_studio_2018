/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Text.cpp
*/

#include <memory>

#include "Utils/Color.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Components/Text.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Components/Text.hpp"
#include "ECS/Interfaces/IEntity.hpp"

Game::Entity::Text::Text(const std::wstring &&text, const Engine::Math::Vec2i &pos, const Engine::Utils::Color &color,
                         const std::string &font)
    : AEntity(AEntity::Type::TEXT)
{
    std::shared_ptr<Engine::ECS::IComponent> _text = std::make_shared<Engine::ECS::Component::Text>(text, pos, color, font);
    addComponent(_text);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>(pos);
    addComponent(_renderer);
}
