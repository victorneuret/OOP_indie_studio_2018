/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.cpp
*/

#include "ECS/Components/Button.hpp"
#include "ECS/Manager.hpp"

Engine::ECS::Component::Button::Button(const decltype(_bounds) &bounds, const decltype(_text) &text)
    : AComponent{"Button"}, _text{std::wstring{text}}, _bounds{bounds}
{
    const auto renderer = std::dynamic_pointer_cast<System::Renderer>(Manager::getInstance().getSystemsByID("Renderer"));

    _button = renderer->createButton(_bounds, _text);
}

decltype(Engine::ECS::Component::Button::_button) Engine::ECS::Component::Button::getButton() const noexcept
{
    return _button;
}

void Engine::ECS::Component::Button::onClick()
{
}
