/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Math/Rect.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Button;
}

class Engine::ECS::Component::Button : public Engine::ECS::AComponent<Engine::ECS::Component::Button> {
protected:
    std::wstring _text{};
    Engine::Math::Rect_i _bounds{};
    irr::gui::IGUIButton *_button{nullptr};

public:
    Button(const Engine::ECS::System::Renderer &renderer, const decltype(_bounds) &pos, const decltype(_text) &text);
    Button(const Button &) = delete;
    Button &operator=(const Button &) = delete;

    decltype(_button) getButton() const noexcept;
    void onClick();
};
