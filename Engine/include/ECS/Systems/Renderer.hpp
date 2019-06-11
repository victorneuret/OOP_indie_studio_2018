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

#include "Math/Rect.hpp"
#include "Utils/Color.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Abstracts/ASystem.hpp"
#include "ECS/Systems/EventHandler.hpp"

namespace Engine::ECS::System {
    class Renderer;
}

class Engine::ECS::System::Renderer final : public ASystem {
private:

    std::wstring _windowName{};
    Math::Vec2u _windowSize{0, 0};

    EventHandler _eventHandler{};
    decltype(irr::createDevice()) _window{nullptr};
    decltype(_window->getVideoDriver()) _videoDriver{nullptr};
    decltype(_window->getSceneManager()) _sceneManager{nullptr};
    decltype(_window->getGUIEnvironment()) _GUIEnvironment{nullptr};

public:
    explicit Renderer(const decltype(_windowName) &windowName, const decltype(_windowSize) &windowSize = Math::Vec2u{1920, 1080});
    Renderer &operator=(const Renderer &) = delete;
    Renderer(const Renderer &) = delete;
    ~Renderer() override;

    void update(double dt) override;
    void draw(const std::shared_ptr<IEntity> &entity) const;
    void refresh() const;
    bool closeRequested() const noexcept;

    irr::scene::IAnimatedMeshSceneNode *create3DModel(const std::string &res) const;
    irr::gui::IGUIFont *createFont(const std::string &fontPath) const;

    void drawRectangle(const ::Engine::Math::Rect_i &pos, const Utils::Color &color) const;

    void drawText(const std::shared_ptr<IEntity> &entity) const;
    void draw3DModel(const std::shared_ptr<IEntity> &entity) const;
    void drawButton(const std::shared_ptr<IEntity> &entity) const;
    void drawSlider(const std::shared_ptr<IEntity> &entity) const;
    void drawImage(const std::shared_ptr<IEntity> &entity) const;

    decltype(_window) getWindow();
    decltype(_videoDriver) getVideoDriver() const noexcept;
    decltype(_sceneManager) getSceneManager() const noexcept;
    decltype(_GUIEnvironment) getGUIEnvironment() const noexcept;
    decltype(_eventHandler) *getEventHandler() noexcept;
};
