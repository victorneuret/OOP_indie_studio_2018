/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.cpp
*/
#include <iostream>

#include "ECS/Components/Button.hpp"
#include "ECS/Manager.hpp"

Engine::ECS::Component::Button::Button(const decltype(_bounds) &bounds, const decltype(_color) &color, const decltype(_func) &func)
    : AComponent("Button"), _bounds{bounds}, _color{color}, _func{func}
{}

decltype(Engine::ECS::Component::Button::_bounds) &Engine::ECS::Component::Button::getBounds() noexcept
{
    return _bounds;
}

decltype(Engine::ECS::Component::Button::_color) &Engine::ECS::Component::Button::getColor() noexcept
{
    return _color;
}

void Engine::ECS::Component::Button::onClick() const
{
    if (_func != nullptr)
        _func();
}
