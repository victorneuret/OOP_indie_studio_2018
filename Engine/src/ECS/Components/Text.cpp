/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Text.cpp
*/

#include "ECS/Components/Text.hpp"
#include "ECS/Engine.hpp"

Engine::ECS::Component::Text::Text(const decltype(_string) &string, const decltype(_pos) &pos, const decltype(_color) &color, const decltype(_fontPath) &fontPath)
    : AComponent{"Text"}, _string{std::wstring{string}}, _pos{pos}, _color{color}, _fontPath{std::string{fontPath}}
{
    const auto renderer = std::dynamic_pointer_cast<System::Renderer>(Engine::getInstance().getSystemsByID("Renderer"));

    _font = renderer->createFont(_fontPath);

}

decltype(Engine::ECS::Component::Text::_string) Engine::ECS::Component::Text::getString() const noexcept
{
    return _string;
}

void Engine::ECS::Component::Text::setString(const decltype(_string) &string) noexcept
{
    _string = string;
}

decltype(Engine::ECS::Component::Text::_pos) Engine::ECS::Component::Text::getPos() const noexcept
{
    return _pos;
}

void Engine::ECS::Component::Text::setPos(const decltype(ECS::Component::Text::_pos) &pos) noexcept
{
    _pos = pos;
}

decltype(Engine::ECS::Component::Text::_color) Engine::ECS::Component::Text::getColor() const noexcept
{
    return _color;
}

void Engine::ECS::Component::Text::setColor(const Utils::Color &color) noexcept
{
    _color = color;
}

decltype(Engine::ECS::Component::Text::_fontPath) Engine::ECS::Component::Text::getFontPath() const noexcept
{
    return _fontPath;
}

decltype(Engine::ECS::Component::Text::_font) Engine::ECS::Component::Text::getFont() const noexcept
{
    return _font;
}
