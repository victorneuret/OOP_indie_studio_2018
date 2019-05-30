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

Engine::ECS::Component::Renderer::Renderer(Engine::ECS::System::Renderer &renderer, const std::string &model, const std::string &texture, const type &type)
    : AComponent{"Renderer"}, _type{type}, _node{renderer.create3DModel(model)}, _texture{texture}
{}

Engine::ECS::Component::Renderer::Renderer(Engine::ECS::System::Renderer &renderer, const std::wstring &text, Engine::Math::Vec2<int32_t> pos, const Engine::Utils::Color &color, const std::string &font)
    : AComponent{"Renderer"}, _type{Engine::ECS::Component::Renderer::type::TEXT}, _pos{pos}, _text{text}, _font{renderer.createFont(font)}, _color{color}
{
    if (_font == nullptr)
        throw MemoryException<Memory_Allocation_Failed>("Font pointer is null");
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

decltype(Engine::ECS::Component::Renderer::_font) Engine::ECS::Component::Renderer::getFont() const noexcept
{
    return _font;
}

decltype(Engine::ECS::Component::Renderer::_text) Engine::ECS::Component::Renderer::getText() const noexcept
{
    return _text;
}

decltype(Engine::ECS::Component::Renderer::_pos) Engine::ECS::Component::Renderer::getPosition() const noexcept
{
    return _pos;
}

decltype(Engine::ECS::Component::Renderer::_color) Engine::ECS::Component::Renderer::getColor() const noexcept
{
    return _color;
}
