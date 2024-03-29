/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.hpp
*/

#pragma once

#include <memory>
#include <string>

#include "ECS/Manager.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "Math/Vector/Vec2.hpp"

constexpr int APP_SUCCESS = 0;
constexpr int APP_FAILURE = 84;

namespace Engine {
    class GameApplication;
}

class Engine::GameApplication {
private:
    const std::wstring _title;
    const Math::Vec2u _dimensions;
    decltype(Engine::ECS::Manager::getInstance()) _ecsManager = Engine::ECS::Manager::getInstance();

    void _startup();
    void _tick(double dt, std::shared_ptr<Engine::ECS::System::Renderer> &renderer);
    void _loop();
public:
    GameApplication(const decltype(_title) &title, long width, long height);
    GameApplication(const decltype(_title) &title, const decltype(_dimensions) &winDim);
    virtual ~GameApplication() = default;

    GameApplication(const GameApplication &) = delete;
    GameApplication &operator=(const GameApplication &) = delete;

    virtual void onAppStartup() = 0;
    virtual void tick(double deltaTime) = 0;
    virtual void onAppShutdown() = 0;
    virtual void onAppCrash() = 0;

    virtual bool run() final;

    virtual decltype(_title) &getTitle() const noexcept final;
    virtual decltype(_dimensions) &getDimensions() const noexcept final;
};
