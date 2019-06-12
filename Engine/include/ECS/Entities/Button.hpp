/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.hpp
*/

#pragma once

#include <string>

#include "Utils/Color.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Interfaces/Entities/IClickable.hpp"
#include "ECS/Interfaces/Entities/IHoverable.hpp"

namespace Engine::ECS::Entity {
    class Button;
}

class Engine::ECS::Entity::Button final : public Engine::ECS::Entity::IClickable, public Engine::ECS::Entity::IHoverable, public Engine::ECS::AEntity {
public:
    explicit Button(const Engine::Math::Rect_i &pos, const std::wstring &text, const Engine::Utils::Color &color,
                    const Engine::Utils::Color &textColor = Engine::Utils::Color{0, 0, 0});
    Button(const Button &) = delete;
    Button &operator=(const Button &) = delete;

    ~Button() final = default;

    void onHover() override;
    void onRelease() override;
    void onPressed() override;
};
