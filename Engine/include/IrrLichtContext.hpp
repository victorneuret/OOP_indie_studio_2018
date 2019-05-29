/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** IrrLichtContext.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include "Math/Vector/Vec2.hpp"

namespace Engine {
    class IrrLichtContext;
}

class Engine::IrrLichtContext final {
private:
    decltype(irr::createDevice()) _device{nullptr};
    decltype(_device->getVideoDriver()) _driver{nullptr};
    decltype(_device->getSceneManager()) _scnMgr{nullptr};
    decltype(_device->getGUIEnvironment()) _guiEnv{nullptr};
public:
    IrrLichtContext(const wchar_t *text, const Math::Vec2<irr::u32> &dimensions);
    virtual ~IrrLichtContext();

    IrrLichtContext(const IrrLichtContext &) = delete;
    IrrLichtContext &operator=(const IrrLichtContext &) = delete;

    decltype(Engine::IrrLichtContext::_device) getDevice() const noexcept;
    decltype(Engine::IrrLichtContext::_driver) getDriver() const noexcept;
    decltype(Engine::IrrLichtContext::_scnMgr) getScnMgr() const noexcept;
    decltype(Engine::IrrLichtContext::_guiEnv) getGuiEnv() const noexcept;
};
