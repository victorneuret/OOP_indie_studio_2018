/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.cpp
*/

#include "ECS/Entities/Button.hpp"
#include "ECS/Components/Text.hpp"
#include "ECS/Components/Button.hpp"
#include "Math/Vector/Vec2.hpp"

Game::Entity::Button::Button(const Engine::Math::Rect_i &bounds, const std::wstring &string, const Engine::Utils::Color &buttonColor, const Engine::Utils::Color &textColor)
    : AEntity(AEntity::Type::BUTTON)
{
    std::shared_ptr<Engine::ECS::IComponent> button = std::make_shared<Engine::ECS::Component::Button>(bounds, buttonColor);
    addComponent(button);

    std::shared_ptr<Engine::ECS::IComponent> text = std::make_shared<Engine::ECS::Component::Text>(string, Engine::Math::Vec2i{0, 0}, textColor);
    addComponent(text);

    auto tmpText = std::dynamic_pointer_cast<Engine::ECS::Component::Text>(text);
    auto textSizes = Engine::Math::Vec2i{static_cast<int>(tmpText->getFont()->getDimension(tmpText->getString().c_str()).Width), static_cast<int>(tmpText->getFont()->getDimension(tmpText->getString().c_str()).Height)};
    tmpText->setPos(Engine::Math::Vec2i{bounds.x + (bounds.w / 2) - (textSizes.x / 2), bounds.y + (bounds.h / 2) - (textSizes.y / 2)});

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}

void Game::Entity::Button::onHover()
{
    throw std::runtime_error{"Hover"};
}

void Game::Entity::Button::onRelease()
{
    throw std::runtime_error{"Released"};
}

void Game::Entity::Button::onPressed()
{
    throw std::runtime_error{"Pressed"};
}
