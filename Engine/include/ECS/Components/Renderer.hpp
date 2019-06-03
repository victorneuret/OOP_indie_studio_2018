/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.hpp
*/

#pragma once

#include <string>
#include <irrlicht/irrlicht.h>

#include "Utils/Colors.hpp"
#include "Math/Vector/Vec3.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Renderer;
}

#include "ECS/Systems/Renderer.hpp"

class Engine::ECS::Component::Renderer : public AComponent<Renderer> {
protected:
    bool _doRender{true};
    Math::Vec2<int32_t> _pos{0, 0};

public:
    Renderer(Math::Vec2<int32_t> pos = Math::Vec2<int32_t>{0, 0});
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    ~Renderer();

    void setDoRender(bool doRender) noexcept;
    decltype(_doRender) doRender() const noexcept;
    decltype(_pos) getPosition() const noexcept;
};
