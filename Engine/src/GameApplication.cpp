/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.cpp
*/

#include "GameApplication.hpp"
#include "Utils/TypeDisplayer.hpp"

Engine::GameApplication::GameApplication(const decltype(_title) &title, long width, long height)
    : GameApplication(title, Math::Vec2<irr::u32>(width, height))
{
}

Engine::GameApplication::GameApplication(const decltype(_title) &title, const decltype(_dimensions) &dimensions)
    : _title(decltype(_title)(title)), _dimensions(dimensions), _context(_title.c_str(), dimensions)
{
}

void Engine::GameApplication::start()
{
}

decltype(Engine::GameApplication::_title) &Engine::GameApplication::getTitle() const noexcept
{
    return _title;
}

decltype(Engine::GameApplication::_dimensions) &Engine::GameApplication::getDimensions() const noexcept
{
    return _dimensions;
}
