/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** 3DModel.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Model3D;
}


class Engine::ECS::Component::Model3D : public Engine::ECS::AComponent<Engine::ECS::Component::Model3D> {
protected:
    irr::scene::IAnimatedMeshSceneNode *_node{nullptr};
    std::string _model{};
    std::string _texture{};

public:
    Model3D(const Engine::ECS::System::Renderer &renderer, const std::string &model, const std::string &texture);
    Model3D(const Model3D &) = delete;
    Model3D &operator=(const Model3D &) = delete;

    decltype(_model) &getModel() noexcept;
    decltype(_texture) &getTexture() noexcept;
    decltype(_node) &getNode() noexcept;
};
