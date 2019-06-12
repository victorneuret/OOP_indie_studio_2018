/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Image.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Math/Rect.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"
#include "Math/Vector/Vec2.hpp"

namespace Engine::ECS::Component {
    class Image;
}

class Engine::ECS::Component::Image : public Engine::ECS::AComponent<Engine::ECS::Component::Image> {
protected:
    std::string _texturePath{};
    irr::video::ITexture *_texture{};
    Math::Vec2u _position{};
    Math::Vec2u _size{};
    irr::gui::IGUIImage *_guiImage{};

public:
    Image(const decltype(_texturePath) &texturePath, const decltype(_position) &position);
    Image(const Image &) = delete;
    Image &operator=(const Image &) = delete;

    decltype(_texturePath) getTexturePath() const noexcept;
    decltype(_texture) getTexture() const noexcept;
    decltype(_position) getPosition() const noexcept;
    decltype(_size) getSize() const noexcept;
    decltype(_guiImage) getGUIImage() const noexcept;

    void setPosition(const decltype(_position) &position) noexcept;
    void setSize(const decltype(_size) &size) noexcept;
};
