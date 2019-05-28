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

namespace Engine::ECS::System {
    class Renderer;
}

class Engine::ECS::System::Renderer final : public Engine::ECS::ASystem<Engine::ECS::System::Renderer> {
private:
    std::string _windowName{};
    Math::Vec2u _windowSize{0, 0};

    irr::IrrlichtDevice *_window{nullptr};
    irr::video::IVideoDriver *_videoDrivers{nullptr};
    irr::scene::ISceneManager *_sceneManager{nullptr};
    irr::gui::IGUIEnvironment *_GUIEnvironment{nullptr};

public:
    explicit Renderer(const std::string &windowName, const Engine::Math::Vec2u &windowSize = Engine::Math::Vec2u{1920, 1080});
    Renderer &operator=(const Renderer &) = delete;
    Renderer(const Renderer &) = delete;
    ~Renderer() override;

    void update(double dt) override;
};
