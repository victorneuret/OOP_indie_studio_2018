/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.cpp
*/

#include "Utils/Logger.hpp"
#include "ECS/Engine.hpp"
#include "Utils/Colors.hpp"
#include "GameApplication.hpp"
#include "Exception/AException.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Math/Vector/Vec3.hpp"

Engine::GameApplication::GameApplication(const decltype(_title) &title, long width, long height)
    : GameApplication(title, Math::Vec2<irr::u32>(width, height))
{
}

Engine::GameApplication::GameApplication(const decltype(_title) &title, const decltype(_dimensions) &dimensions)
    : _title(decltype(_title)(title)), _dimensions(dimensions)
{
    std::shared_ptr<Engine::ECS::ISystem> renderer = std::make_shared<Engine::ECS::System::Renderer>(_title, _dimensions);
    Engine::ECS::Engine::getInstance().addSystem(renderer);
}

void Engine::GameApplication::_startup()
{
    std::shared_ptr<Engine::ECS::ISystem> audio = std::make_shared<Engine::ECS::System::Audio>();
    Engine::ECS::Engine::getInstance().addSystem(audio);
}

void Engine::GameApplication::_loop()
{
    std::chrono::duration<double> elapsed = std::chrono::seconds(0);
    auto begin = std::chrono::system_clock::now();
    decltype(begin) end;
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::System::Renderer>(Engine::ECS::Engine::getInstance().getSystemsByID("Renderer"));

    while (!renderer->closeRequested()) {
        auto dt = elapsed.count();

        renderer->refresh();
        tick(dt);

        for (const auto &entity : Engine::ECS::Engine::getInstance().getEntities())
            renderer->draw(entity);
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
