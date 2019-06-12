/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.hpp
*/

#pragma once

#include <string>
#include <functional>

#include "Utils/Color.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Interfaces/Entities/IGuiElement.hpp"

namespace Engine::ECS::Entity {
    class Button;
}

class Engine::ECS::Entity::Button : public Engine::ECS::Entity::IGuiElement, public Engine::ECS::AEntity {
public:
    explicit Button(const Engine::Math::Rect_i &pos, const std::wstring &text, const std::function<void()> &func,
                    const Engine::Utils::Color &color = {0, 0, 0}, const Engine::Utils::Color &textColor = {0, 0, 0});
    Button(const Button &) = delete;
    Button &operator=(const Button &) = delete;

    ~Button() final = default;
    bool onEvent(irr::gui::EGUI_EVENT_TYPE eventType) override;
};
