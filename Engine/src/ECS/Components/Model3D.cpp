/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Model3D.cpp
*/

#include "ECS/Components/Model3D.hpp"

Engine::ECS::Component::Model3D::Model3D(const Engine::ECS::System::Renderer &renderer, const std::string &model, const std::string &texture)
        : AComponent("Model3D"), _node{renderer.create3DModel(model, texture)}, _model{std::string{model}}, _texture{std::string{texture}}
{
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
