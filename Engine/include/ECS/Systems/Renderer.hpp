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
#include "Utils/Colors.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class Renderer;
}

class Engine::ECS::System::Renderer final : public ASystem<System::Renderer> {
private:
    class EventMiddleware : public irr::IEventReceiver {
    protected:
        std::vector<std::shared_ptr<irr::IEventReceiver>> _handlers;

    public:
        bool OnEvent(const irr::SEvent &event);
        void addEventHandler(const std::shared_ptr<irr::IEventReceiver> &handler);
    };

    std::wstring _windowName{};
    Math::Vec2u _windowSize{0, 0};

    decltype(irr::createDevice()) _window{nullptr};
    decltype(_window->getVideoDriver()) _videoDrivers{nullptr};
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

    decltype(_window->getVideoDriver()) getVideoDriver() const;
};
