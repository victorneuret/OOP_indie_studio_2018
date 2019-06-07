/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.hpp
*/

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ECS/Abstracts/AEntity.hpp"
#include "Exception/AException.hpp"
#include "Math/Rect.hpp"

namespace Game::Entity {
    class Button;
}

class Game::Entity::Button final : public Engine::ECS::AEntity<Button> {
public:
    explicit Button(const Engine::Math::Rect_i &pos, const std::wstring &text);
    Button(const Button &) = delete;
    Button &operator=(const Button &) = delete;

    ~Button() final = default;
};
