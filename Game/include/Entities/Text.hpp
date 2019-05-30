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
protected:
    std::wstring _text{L""};

public:
    explicit Text(Engine::ECS::System::Renderer &renderer, const decltype(_text) &&text, Engine::Math::Vec2<int32_t> pos, const Engine::Utils::Color &color, const std::string &font = "");
    Text(const Text &) = delete;
    Text &operator=(const Text &) = delete;

    ~Text() = default;
};
