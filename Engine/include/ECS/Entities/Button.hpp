/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.hpp
*/

#pragma once

#include <string>

#include "Utils/Colors.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Interfaces/Entities/IClickable.hpp"
#include "ECS/Interfaces/Entities/IHoverable.hpp"

namespace Game::Entity {
    class Button;
}

class Game::Entity::Button final : public Engine::ECS::Entity::IClickable, public Engine::ECS::Entity::IHoverable, public Engine::ECS::AEntity<Button> {
public:
    explicit Button(const Engine::Math::Rect_i &pos, const std::wstring &text, const Engine::Utils::Color &color, const Engine::Utils::Color &textColor = Engine::Utils::Color{0, 0, 0});
    Button(const Button &) = delete;
    Button &operator=(const Button &) = delete;

    ~Button() final = default;

    void onHover() final;
    void onRelease() final;
    void onPressed() final;
};
