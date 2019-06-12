/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Image.hpp
*/

#pragma once

#include <string>

#include "Utils/Color.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "Math/Vector/Vec2.hpp"

namespace Engine::Entity {
    class Image;
}

class Engine::Entity::Image final : public Engine::ECS::AEntity<Image> {
public:
    explicit Image(const std::string &texturePath, const Math::Vec2u &position);
    Image(const Image &) = delete;
    Image &operator=(const Image &) = delete;

    ~Image() final = default;
};