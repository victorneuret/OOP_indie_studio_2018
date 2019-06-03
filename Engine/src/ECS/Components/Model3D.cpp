/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Model3D.cpp
*/

#include "ECS/Components/Model3D.hpp"

Engine::ECS::Component::Model3D::Model3D(const Engine::ECS::System::Renderer &, const std::string &model, const std::string &texture) // TODO 3DMesh
        : AComponent("Model3D"), _model{std::string{model}}, _texture{std::string{texture}}
{
}

decltype(Engine::ECS::Component::Model3D::_model) Engine::ECS::Component::Model3D::getModel() const noexcept
{
    return _model;
}

decltype(Engine::ECS::Component::Model3D::_texture) Engine::ECS::Component::Model3D::getTexture() const noexcept
{
    return _texture;
}

decltype(Engine::ECS::Component::Model3D::_node) Engine::ECS::Component::Model3D::getNode() const noexcept
{
    return _node;
}
