/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Text.hpp
*/

#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Exception/AException.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "Utils/Color.hpp"

namespace Engine::ECS::Entity {
    class Text;
}

class Engine::ECS::Entity::Text final : public Engine::ECS::AEntity {
public:
    explicit Text(const std::wstring &&text, const Engine::Math::Vec2i &pos, const Engine::Utils::Color &color,
                  const std::string &font = "");
    Text(const Text &) = delete;
    Text &operator=(const Text &) = delete;

    ~Text() final = default;
};
