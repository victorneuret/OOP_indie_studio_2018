/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Slider.cpp
*/

#include "ECS/Components/Slider.hpp"

Engine::ECS::Component::Slider::Slider(const decltype(_bounds) &bounds, const decltype(_backgroundColor) &backgroundColor, const decltype(_valueColor) &valueColor)
    : AComponent{"Slider"}, _bounds{bounds}, _backgroundColor{backgroundColor}, _valueColor{valueColor}
{
}

const decltype(Engine::ECS::Component::Slider::_bounds) &Engine::ECS::Component::Slider::getBounds() const noexcept
{
    return _bounds;
}

const decltype(Engine::ECS::Component::Slider::_backgroundColor) &Engine::ECS::Component::Slider::getBackgroundColor() const noexcept
{
    return _backgroundColor;
}

const decltype(Engine::ECS::Component::Slider::_valueColor) &Engine::ECS::Component::Slider::getValueColor() const noexcept
{
    return _valueColor;
}

const decltype(Engine::ECS::Component::Slider::_value) &Engine::ECS::Component::Slider::getValue() const noexcept
{
    return _value;
}
