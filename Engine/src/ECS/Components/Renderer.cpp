/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include "ECS/Components/Renderer.hpp"
#include "Exception/NotImplementedException.hpp"

Engine::ECS::Component::Renderer::Renderer()
    : AComponent{"Renderer"}
{}

void Engine::ECS::Component::Renderer::setDoRender(bool doRender) noexcept
{
    _doRender = doRender;
}

bool Engine::ECS::Component::Renderer::getDoRenderer() const noexcept
{
    return _doRender;
}

void Engine::ECS::Component::Renderer::getRenderResult() const
{
    throw NotImplementedException{"Engine::Component::Renderer::getRenderResult"};
}
