/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Model3D.cpp
*/

#include "ECS/Components/Model3D.hpp"

Engine::ECS::Component::Model3D::Model3D(const Engine::ECS::System::Renderer &renderer, const Engine::Math::Vec3f &pos, const decltype(_model) &model, const decltype(_texture) &texture)
        : AComponent("Model3D"), _node{renderer.create3DModel(model, texture)}, _model{std::string{model}}, _texture{std::string{texture}}
{
    _node->setPosition(irr::core::vector3df{pos.x, pos.y, pos.z});
}

decltype(Engine::ECS::Component::Model3D::_model) &Engine::ECS::Component::Model3D::getModel() noexcept
{
    return _model;
}

decltype(Engine::ECS::Component::Model3D::_texture) &Engine::ECS::Component::Model3D::getTexture() noexcept
{
    return _texture;
}

decltype(Engine::ECS::Component::Model3D::_node) &Engine::ECS::Component::Model3D::getNode() noexcept
{
    return _node;
}
