/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** IrrLichtContext.cpp
*/

#include "IrrLichtContext.hpp"

Engine::IrrLichtContext::IrrLichtContext(const wchar_t *text, const Engine::Math::Vec2<irr::u32> &dimensions)
{
    _device = irr::createDevice(irr::video::EDT_OPENGL,
                                irr::core::dimension2d<irr::u32>(dimensions.x, dimensions.y),
                                16, false, false, false, nullptr);
    _driver = _device->getVideoDriver();
    _scnMgr = _device->getSceneManager();
    _guiEnv = _device->getGUIEnvironment();

    _device->setWindowCaption(text);
}

Engine::IrrLichtContext::~IrrLichtContext()
{
    _device->drop();
}

decltype(Engine::IrrLichtContext::_device) Engine::IrrLichtContext::getDevice() const noexcept
{
    return _device;
}

decltype(Engine::IrrLichtContext::_driver) Engine::IrrLichtContext::getDriver() const noexcept
{
    return _driver;
}

decltype(Engine::IrrLichtContext::_scnMgr) Engine::IrrLichtContext::getScnMgr() const noexcept
{
    return _scnMgr;
}

decltype(Engine::IrrLichtContext::_guiEnv) Engine::IrrLichtContext::getGuiEnv() const noexcept
{
    return _guiEnv;
}
