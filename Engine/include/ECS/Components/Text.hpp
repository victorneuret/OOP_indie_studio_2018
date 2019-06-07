/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Text.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Utils/Color.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Text;
}

class Engine::ECS::Component::Text : public Engine::ECS::AComponent<Engine::ECS::Component::Text> {
protected:
    std::wstring _string{};
    Math::Vec2i _pos{};
    Engine::Utils::Color _color{255, 255, 255};
    std::string _fontPath{};
    irr::gui::IGUIFont *_font{nullptr};

public:
    Text(const decltype(_string) &string, const decltype(_pos) &pos, const decltype(_color) &color = Engine::Utils::Color{255, 255, 255}, const decltype(_fontPath) &fontPath = "");
    Text(const Text &) = delete;
    Text &operator=(const Text &) = delete;

    decltype(_string) getString() const noexcept;
    void setString(const decltype(_string) &string) noexcept;

    decltype(_pos) getPos() const noexcept;
    void setPos(const decltype(_pos) &pos) noexcept;

    decltype(_color) getColor() const noexcept;
    void setColor(const decltype(_color) &color) noexcept;

    decltype(_fontPath) getFontPath() const noexcept;
    decltype(_font) getFont() const noexcept;
};
