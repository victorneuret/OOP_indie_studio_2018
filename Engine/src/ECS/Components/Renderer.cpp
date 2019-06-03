/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <iostream> // DEBUG

#include "ECS/Components/Renderer.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/NotImplementedException.hpp"

Engine::ECS::Component::Renderer::Renderer(Engine::Math::Vec2<int32_t> pos)
    : AComponent{"Renderer"}, _pos{pos}
{
}

Engine::ECS::Component::Renderer::~Renderer()
{}

void Engine::ECS::Component::Renderer::setDoRender(bool doRender) noexcept
{
    _doRender = doRender;
}

bool Engine::ECS::Component::Renderer::doRenderer() const noexcept
{
    return _doRender;
}

decltype(Engine::ECS::Component::Renderer::_pos) Engine::ECS::Component::Renderer::getPosition() const noexcept
{
    return _pos;
}
