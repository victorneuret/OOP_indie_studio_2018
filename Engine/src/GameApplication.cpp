/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.cpp
*/

#include <irrlicht/irrTypes.h>
#include <chrono>
#include <vector>

#include "GameApplication.hpp"
#include "ECS/Interfaces/ISystem.hpp"
#include "ECS/Systems/Event/ButtonEvent.hpp"
#include "ECS/Systems/Input/JoystickInput.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "../../Game/include/Systems/JoystickHandler.hpp"
#include "../../Game/include/Systems/KeyboardHandler.hpp"
#include "ECS/Systems/InputHandler.hpp"
#include "ECS/Interfaces/InputType.hpp"
#include "ECS/Systems/Input/MouseInput.hpp"
#include "ECS/Systems/Particle.hpp"
#include "Utils/Logger.hpp"
#include "ECS/Manager.hpp"
#include "Utils/Color.hpp"
#include "ECS/Entities/Text.hpp"
#include "ECS/Entities/Button.hpp"
#include "ECS/Entities/Particle.hpp"
#include "GameApplication.hpp"
#include "ECS/Interfaces/ISystem.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Math/Vector/Vec3.hpp"
#include "ECS/Systems/Timer.hpp"

Engine::GameApplication::GameApplication(const decltype(_title) &title, long width, long height)
    : GameApplication(title, Math::Vec2<irr::u32>(width, height))
{}

Engine::GameApplication::GameApplication(const decltype(_title) &title, const decltype(_dimensions) &dimensions)
    : _title{decltype(_title){title}}, _dimensions{dimensions}
{
}

void Engine::GameApplication::_startup()
{
    std::shared_ptr<Engine::ECS::ISystem> renderer = std::make_shared<Engine::ECS::System::Renderer>(_title, _dimensions);
    _ecsManager.addSystem(renderer);

    std::shared_ptr<Engine::ECS::ISystem> audio = std::make_shared<Engine::ECS::System::Audio>();
    std::shared_ptr<Engine::ECS::ISystem> timer = std::make_shared<Engine::ECS::System::Timer>();
    std::shared_ptr<Engine::ECS::ISystem> button = std::make_shared<Engine::ECS::System::ButtonEvent>();
    std::shared_ptr<Engine::ECS::ISystem> keyboard = std::make_shared<Engine::ECS::System::KeyboardInput>();
    std::shared_ptr<Engine::ECS::ISystem> mouse = std::make_shared<Engine::ECS::System::MouseInput>();
    std::shared_ptr<Engine::ECS::ISystem> joystick = std::make_shared<Engine::ECS::System::JoystickInput>();
    std::shared_ptr<Engine::ECS::ISystem> particles = std::make_shared<Engine::ECS::System::Particle>();
    std::shared_ptr<Engine::ECS::ISystem> handler = std::make_shared<Engine::ECS::System::InputHandler>();

    _ecsManager.addSystem(timer);
    _ecsManager.addSystem(audio);
    _ecsManager.addSystem(button);
    _ecsManager.addSystem(keyboard);
    _ecsManager.addSystem(mouse);
    _ecsManager.addSystem(joystick);
    _ecsManager.addSystem(particles);
    _ecsManager.addSystem(handler);
}

void Engine::GameApplication::_tick(double dt, std::shared_ptr<Engine::ECS::System::Renderer> &renderer)
{
    for (const auto &system : _ecsManager.getSystems())
        if (system->getID() != "Renderer")
            system->update(dt);
    tick(dt);
    _ecsManager.sceneManager(dt, renderer);
}

void Engine::GameApplication::_loop()
{
    std::chrono::duration<double> elapsed = std::chrono::seconds(0);
    auto begin = std::chrono::system_clock::now();
    decltype(begin) end;
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(_ecsManager.getSystemByID("Renderer"));

    while (!renderer->closeRequested()) {
        auto dt = elapsed.count();

        renderer->refresh();
        _tick(dt, renderer);
        renderer->update(dt);

        end = std::chrono::system_clock::now();
        elapsed = end - begin;
        begin = end;
    }
}

bool Engine::GameApplication::run()
{
    _startup();
    onAppStartup();

    try {
        _loop();
    } catch (const AException &e) {
        Engine::Logger::getInstance().error("GameApplication: uncaught exception -> " + e.what_stdstr());
        onAppCrash();
        return false;
    }

    onAppShutdown();
    return true;
}

decltype(Engine::GameApplication::_title) &Engine::GameApplication::getTitle() const noexcept
{
    return _title;
}

decltype(Engine::GameApplication::_dimensions) &Engine::GameApplication::getDimensions() const noexcept
{
    return _dimensions;
}
