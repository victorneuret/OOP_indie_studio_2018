/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** 3DModel.hpp
*/

#pragma once

#include <string>

#include <irrlicht/irrlicht.h>

#include "ECS/Abstracts/AComponent.hpp"
#include "Math/Vector/Vec3.hpp"

namespace Engine::ECS::Component {
    class Model3D;
}

class Engine::ECS::Component::Model3D : public AComponent {
protected:
    irr::scene::IAnimatedMeshSceneNode *_node{nullptr};
    std::string _model{};
    std::string _texture{};
    uint32_t _textureLayer{0};

public:
    Model3D(const Math::Vec3f &pos, const decltype(_model) &model);
    Model3D(const Model3D &) = delete;
    Model3D &operator=(const Model3D &) = delete;

    ~Model3D() override = default;

    decltype(_model) &getModel() noexcept;
    decltype(_texture) &getTexture() noexcept;
    decltype(_node) &getNode() noexcept;

    void setPosition(const Math::Vec3f &pos);
    void setScale(const Math::Vec3f &scale);
    void addTexture(const decltype(_texture) &texture);
};
