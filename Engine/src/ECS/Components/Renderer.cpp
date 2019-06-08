/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include "ECS/Components/Renderer.hpp"

Engine::ECS::Component::Renderer::Renderer(const decltype(_pos) &pos)
    : AComponent{"Renderer"}, _pos{pos}
{
}

void Engine::ECS::Component::Renderer::setDoRender(bool doRender) noexcept
{
    _doRender = doRender;
}

bool Engine::ECS::Component::Renderer::doRender() const noexcept
{
    return _doRender;
}

decltype(Engine::ECS::Component::Renderer::_pos) Engine::ECS::Component::Renderer::getPosition() const noexcept
{
    return _pos;
}
