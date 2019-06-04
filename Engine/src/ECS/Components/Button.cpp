/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.cpp
*/

#include "ECS/Components/Button.hpp"

Engine::ECS::Component::Button::Button(const Engine::ECS::System::Renderer &renderer, const decltype(_pos) &pos, const decltype(_text) &text)
    : AComponent{"Button"}, _text{std::wstring{text}}, _pos{pos}, _button{renderer.createButton(_pos, _text)}
{
}

decltype(Engine::ECS::Component::Button::_button) Engine::ECS::Component::Button::getButton() const noexcept
{
    return _button;
}

void Engine::ECS::Component::Button::onClick()
{
}
