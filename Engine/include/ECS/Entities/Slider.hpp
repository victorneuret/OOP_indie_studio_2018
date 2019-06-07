/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Slider.hpp
*/

#pragma once

#include <string>

#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Interfaces/Entities/IClickable.hpp"

namespace Game::Entity {
    class Slider;
}

class Game::Entity::Slider final : public Engine::ECS::Entity::IClickable, public Engine::ECS::AEntity<Slider> {
public:
    explicit Slider(const Engine::Math::Rect_i &pos, const Engine::Utils::Color &backgroudColor = Engine::Utils::Color{0, 0, 0}, const Engine::Utils::Color &valueColor  = Engine::Utils::Color{255, 255, 255});
    Slider(const Slider &) = delete;
    Slider &operator=(const Slider &) = delete;

    ~Slider() final = default;
    void onPressed() override;
    void onRelease() override;
};
