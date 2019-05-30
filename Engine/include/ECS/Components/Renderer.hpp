/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.hpp
*/

#pragma once

#include <string>
#include <irrlicht/irrlicht.h>

#include "Utils/Colors.hpp"
#include "Math/Vector/Vec3.hpp"
#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Component {
    class Renderer;
}

#include "ECS/Systems/Renderer.hpp"

class Engine::ECS::Component::Renderer : public AComponent<Renderer> {
public:
    enum class type {
        TEXT = 1,
        MODEL3D = 2,
        MODEL2D = 3
    };

private:

    // Common
    bool _doRender{true};
    type _type;

    Engine::Math::Vec2<int32_t> _pos{0, 0};

    // 3DModels
    irr::scene::IAnimatedMeshSceneNode *_node{nullptr};
    std::string _texture{};

    //Text
    std::wstring _text{};
    irr::gui::IGUIFont *_font{};
    Engine::Utils::Color _color{0, 0, 0};

public:
    Renderer(System::Renderer &renderer, const std::string &model, const std::string &texture, const type &type);
    Renderer(System::Renderer &renderer, const std::wstring &text, Engine::Math::Vec2<int32_t> pos, const Engine::Utils::Color &color, const std::string &font);
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    ~Renderer();

    void setDoRender(bool doRender) noexcept;
    decltype(_doRender) doRenderer() const noexcept;
    decltype(_type) getType() const noexcept;
    decltype(_pos) getPosition() const noexcept;

    // 3DModels
    const decltype(_node) &getNode() noexcept;
    decltype(_texture) getTexture() const noexcept;

    // Text
    decltype(_font) getFont() const noexcept;
    decltype(_text) getText() const noexcept;
    decltype(_color) getColor() const noexcept;
};
