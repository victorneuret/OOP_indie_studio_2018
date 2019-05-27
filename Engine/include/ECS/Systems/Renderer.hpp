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

class Engine::ECS::System::Renderer : public Engine::ECS::ASystem<Engine::ECS::System::Renderer> {
private:
    std::string _windowName{};
    Math::Vec2u _windowSize{0, 0};

    std::unique_ptr<irr::IrrlichtDevice> _window{nullptr};
    std::unique_ptr<irr::video::IVideoDriver> _videoDrivers{nullptr};
    std::unique_ptr<irr::scene::ISceneManager> _sceneManager{nullptr};
    std::unique_ptr<irr::gui::IGUIEnvironment> _GUIEnvironement{nullptr};

public:
    Renderer(std::string &windowName, const Engine::Math::Vec2u &windowSize = Engine::Math::Vec2u{0, 0});
    ~Renderer();
};
