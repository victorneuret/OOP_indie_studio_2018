/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** GameApplication.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <string>

#include "Math/Vector/Vec2.hpp"
#include "IrrLichtContext.hpp"

namespace Engine {
    class GameApplication;
}

class Engine::GameApplication {
private:
    const std::wstring _title;
    const Math::Vec2<irr::u32> _dimensions;
    const IrrLichtContext _context;
public:
    GameApplication(const decltype(_title) &title, long width, long height);
    GameApplication(const decltype(_title) &title, const Math::Vec2<irr::u32> &winDim);
    virtual ~GameApplication() = default;

    GameApplication(const GameApplication &) = delete;
    GameApplication &operator=(const GameApplication &) = delete;

    virtual void tick(double deltaTime) = 0;

    virtual void start() final;

    virtual decltype(_title) &getTitle() const noexcept final;
    virtual decltype(_dimensions) &getDimensions() const noexcept final;
};
