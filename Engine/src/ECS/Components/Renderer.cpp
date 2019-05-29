/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <iostream> // DEBUG

#include "ECS/Components/Renderer.hpp"
#include "Exception/NotImplementedException.hpp"

Engine::ECS::Component::Renderer::Renderer(Engine::ECS::System::Renderer &renderer, const std::string &model, const std::string &texture, const type &type)
    : AComponent{"Renderer"}, _type{type}, _node{renderer.create3DModel(model)}, _texture{texture}
{}

Engine::ECS::Component::Renderer::~Renderer()
{}

void Engine::ECS::Component::Renderer::setDoRender(bool doRender) noexcept
{
    _doRender = doRender;
}

bool Engine::ECS::Component::Renderer::getDoRenderer() const noexcept
{
    return _doRender;
}

decltype(Engine::ECS::Component::Renderer::_type) Engine::ECS::Component::Renderer::getType() const noexcept
{
    return _type;
}

const decltype(Engine::ECS::Component::Renderer::_node) &Engine::ECS::Component::Renderer::getNode() noexcept
{
    return _node;
}

decltype(Engine::ECS::Component::Renderer::_texture) Engine::ECS::Component::Renderer::getTexture() const noexcept
{
    return _texture;
}
