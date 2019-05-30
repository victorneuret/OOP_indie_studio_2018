/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.cpp
*/

#include "Logger.hpp"
#include "GameApplication.hpp"
#include "Exception/AException.hpp"

Engine::GameApplication::GameApplication(const decltype(_title) &title, long width, long height)
    : GameApplication(title, Math::Vec2<irr::u32>(width, height))
{
}

Engine::GameApplication::GameApplication(const decltype(_title) &title, const decltype(_dimensions) &dimensions)
    : _title(decltype(_title)(title)), _dimensions(dimensions), _context(_title.c_str(), dimensions)
{
}

void Engine::GameApplication::_loop()
{
    std::chrono::duration<double> elapsed = std::chrono::seconds(0);
    auto begin = std::chrono::system_clock::now();
    auto end = begin;

    while (_context.getDevice()->run()) {
        _context.getDriver()->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));

        tick(elapsed.count());

        _context.getScnMgr()->drawAll();
        _context.getGuiEnv()->drawAll();
        _context.getDriver()->endScene();

        end = std::chrono::system_clock::now();
        elapsed = end - begin;
        begin = end;
    }
}

bool Engine::GameApplication::run()
{
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

decltype(Engine::GameApplication::_context) &Engine::GameApplication::getContext() const noexcept
{
    return _context;
}