/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.hpp
*/

#pragma once

#include <string>
#include <irrlicht/irrlicht.h>

#include "Math/Vector/Vec3.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Renderer;
}

#include "ECS/Systems/Renderer.hpp"

class Engine::ECS::Component::Renderer : public AComponent<Renderer> {
public:
    enum class type {
        TEXT = 1,
        MODEL3D = 2,
        MODEL2D = 3
    };

private:
    bool _doRender{true};
    type _type;
    irr::scene::IAnimatedMeshSceneNode *_node{nullptr};
    std::string _texture{};

public:
    Renderer(System::Renderer &renderer, const std::string &model, const std::string &texture, const type &type);
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    ~Renderer();

    const decltype(_node) &getNode() noexcept;
    void setDoRender(bool doRender) noexcept;
    decltype(_doRender) getDoRenderer() const noexcept;
    decltype(_type) getType() const noexcept;
    decltype(_texture) getTexture() const noexcept;
};
