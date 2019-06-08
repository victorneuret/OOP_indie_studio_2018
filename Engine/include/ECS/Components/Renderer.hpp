/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.hpp
*/

#pragma once

#include "ECS/Abstracts/AComponent.hpp"
#include "Math/Vector/Vec2.hpp"

namespace Engine::ECS::Component {
    class Renderer;
}

#include "ECS/Systems/Renderer.hpp"

class Engine::ECS::Component::Renderer : public AComponent<Renderer> {
protected:
    bool _doRender{true};
    Math::Vec2i _pos{0, 0};

public:
    explicit Renderer(const decltype(_pos) &pos = Math::Vec2i{0, 0});
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    ~Renderer() override = default;

    void setDoRender(bool doRender) noexcept;
    decltype(_doRender) doRender() const noexcept;
    decltype(_pos) getPosition() const noexcept;
};
