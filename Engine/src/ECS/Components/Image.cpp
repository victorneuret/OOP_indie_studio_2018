/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Image.cpp
*/

#include "ECS/Components/Image.hpp"
#include "ECS/Manager.hpp"

Engine::ECS::Component::Image::Image(const decltype(_texturePath) &texturePath, const decltype(_position) &position)
        : AComponent{"Image"}, _texturePath{texturePath}, _position{position}
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Manager::getInstance().getSystemByID("Renderer"));
    auto driver = renderer->getVideoDriver();
    auto guiEnv = renderer->getGUIEnvironment();

    _texture = driver->getTexture(texturePath.c_str());
    _size = {_texture->getSize().Width, _texture->getSize().Height};
    _guiImage = guiEnv->addImage(_texture, irr::core::vector2d<irr::s32>(_position.x, _position.y));
}

decltype(Engine::ECS::Component::Image::_texturePath) Engine::ECS::Component::Image::getTexturePath() const noexcept
{
    return _texturePath;
}

decltype(Engine::ECS::Component::Image::_texture) Engine::ECS::Component::Image::getTexture() const noexcept
{
    return _texture;
}

decltype(Engine::ECS::Component::Image::_position) Engine::ECS::Component::Image::getPosition() const noexcept
{
    return _position;
}

decltype(Engine::ECS::Component::Image::_size) Engine::ECS::Component::Image::getSize() const noexcept
{
    return _size;
}

decltype(Engine::ECS::Component::Image::_guiImage) Engine::ECS::Component::Image::getGUIImage() const noexcept
{
    return _guiImage;
}

void Engine::ECS::Component::Image::setPosition(const decltype(_position) &position) noexcept
{
    _position = position;
    _guiImage->setRelativePosition(irr::core::position2di{static_cast<int32_t>(position.x), static_cast<int32_t>(position.y)});
}

void Engine::ECS::Component::Image::setSize(const decltype(_size) &size) noexcept
{
    _size = size;
}
