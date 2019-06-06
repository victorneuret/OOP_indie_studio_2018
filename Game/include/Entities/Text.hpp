/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Text.hpp
*/

#pragma once

#include <string>

#include "Utils/Colors.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"

namespace Game::Entity {
    class Text;
}

class Game::Entity::Text final : public Engine::ECS::AEntity<Text> {
public:
    explicit Text(const std::wstring &&text, const Engine::Math::Vec2i &pos, const Engine::Utils::Color &color, const std::string &font = "");
    Text(const Text &) = delete;
    Text &operator=(const Text &) = delete;

    ~Text() final = default;
};
