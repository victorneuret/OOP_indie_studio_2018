/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.hpp
*/

#pragma once

#include <string>
#include <memory>
#include <irrlicht/irrlicht.h>

#include "Math/Vector/Vec2.hpp"
#include "ECS/Abstracts/ASystem.hpp"
#include "ECS/Interfaces/IEntity.hpp"

namespace Engine::ECS::System {
    class Renderer;
}

class Engine::ECS::System::Renderer final : public ASystem<System::Renderer> {
private:
    std::wstring _windowName{};
    Math::Vec2u _windowSize{0, 0};

    irr::IrrlichtDevice *_window{nullptr};
    irr::video::IVideoDriver *_videoDrivers{nullptr};
    irr::scene::ISceneManager *_sceneManager{nullptr};
    irr::gui::IGUIEnvironment *_GUIEnvironment{nullptr};

public:
    explicit Renderer(const std::wstring &windowName, const Math::Vec2u &windowSize = Math::Vec2u{1920, 1080});
    Renderer &operator=(const Renderer &) = delete;
    Renderer(const Renderer &) = delete;
    ~Renderer() override;

    void update(double dt) override;
    void draw(std::shared_ptr<IEntity>) const;
    void refresh() const;
    bool closeRequested() const noexcept;

    irr::scene::IAnimatedMeshSceneNode *create3DModel(const std::string &res) const;
    irr::gui::IGUIFont *createFont(const std::string &fontPath) const;

    void drawText(std::shared_ptr<IEntity>) const;

    void show(std::shared_ptr<IEntity>) const;
    void hide(std::shared_ptr<IEntity>) const;
};
