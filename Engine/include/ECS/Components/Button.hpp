/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.hpp
*/

#pragma once

#include <functional>
#include <irrlicht/irrlicht.h>

#include "Math/Rect.hpp"
#include "Utils/Color.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Button;
}

class Engine::ECS::Component::Button : public Engine::ECS::AComponent {
protected:
    Engine::Math::Rect_i _bounds{};
    Utils::Color _color{0, 0, 0};
    std::function<void ()> _func;

public:
    Button(const decltype(_bounds) &bounds, const decltype(_color) &color);
    Button(const Button &) = delete;
    Button &operator=(const Button &) = delete;

    void onClick() const;
    decltype(_bounds) &getBounds() noexcept;
    decltype(_color) &getColor() noexcept;
};
