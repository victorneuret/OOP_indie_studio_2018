/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.hpp
*/

#pragma once

#include <string>

#include "Math/Vector/Vec3.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Renderer;
}

class Engine::ECS::Component::Renderer : public Engine::ECS::AComponent<Engine::ECS::Component::Renderer> {
private:
    bool _doRender{true};

public:
    Renderer();
    ~Renderer() = default;
    void setDoRender(bool doRender) noexcept;
    decltype(_doRender) getDoRenderer() const noexcept;
    void getRenderResult() const;
};
