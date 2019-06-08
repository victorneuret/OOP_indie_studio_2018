/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Model3D.cpp
*/

#include <memory>

#include "ECS/Systems/Renderer.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Manager.hpp"
#include "Math/Vector/Vec3.hpp"

Engine::ECS::Component::Model3D::Model3D(const Math::Vec3f &pos, const decltype(_model) &model)
    : AComponent("Model3D"), _model{std::string{model}}
{
    const auto renderer = std::dynamic_pointer_cast<System::Renderer>(Manager::getInstance().getSystemByID("Renderer"));

    _node = renderer->create3DModel(model);
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

void Engine::ECS::Component::Model3D::setPosition(const Math::Vec3f &pos)
{
    _node->setPosition(irr::core::vector3df{pos.x, pos.y, pos.z});
}

void Engine::ECS::Component::Model3D::setScale(const Math::Vec3f &scale)
{
    _node->setScale(irr::core::vector3df{scale.x, scale.y, scale.z});
}

void Engine::ECS::Component::Model3D::addTexture(const decltype(_texture) &texture)
{
    auto renderer = std::dynamic_pointer_cast<System::Renderer>(Manager::getInstance().getSystemByID("Renderer"));

    _node->setMaterialTexture(_textureLayer++, renderer->getVideoDriver()->getTexture(texture.c_str()));
}
