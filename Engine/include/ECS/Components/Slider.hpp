/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Slider.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Math/Rect.hpp"
#include "Utils/Color.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Slider;
}

class Engine::ECS::Component::Slider : public Engine::ECS::AComponent {
protected:
    Engine::Math::Rect_i _bounds{};
    Utils::Color _backgroundColor{0, 0, 0};
    Utils::Color _valueColor{0, 0, 0};
    int _value{0};

public:
    Slider(const decltype(_bounds) &bounds, const decltype(_backgroundColor) &backgroundColor, const decltype(_valueColor) &valueColor);
    Slider(const Slider &) = delete;
    Slider &operator=(const Slider &) = delete;

    const decltype(_bounds) &getBounds() const noexcept;
    const decltype(_backgroundColor) &getBackgroundColor() const noexcept;
    const decltype(_valueColor) &getValueColor() const noexcept;
    const decltype(_value) &getValue() const noexcept;
};
