/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <irrlicht/irrlicht.h>

#include "ECS/Systems/Renderer.hpp"

Engine::ECS::System::Renderer::Renderer(std::string &windowName, const Engine::Math::Vec2u &windowSize)
    : _windowName{windowName}, _windowSize{windowSize},
    _window{irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(_windowSize.x, _windowSize.y), 16, false, false, false, nullptr)},
    _videoDrivers{_window->getVideoDriver()},
    _sceneManager{_window->getSceneManager()},
    _GUIEnvironement{_window->getGUIEnvironment()}
{
    _window->setWindowCaption(std::wstring{_windowName.begin(), _windowName.end()}.c_str());
}

Engine::ECS::System::Renderer::~Renderer()
{
    _window->drop();
}
