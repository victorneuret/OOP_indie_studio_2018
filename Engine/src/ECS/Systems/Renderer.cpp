/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <irrlicht/irrlicht.h>

#include "ECS/Systems/Renderer.hpp"
#include "Exception/NotImplementedException.hpp"

Engine::ECS::System::Renderer::Renderer(const std::string &windowName, const Engine::Math::Vec2u &windowSize)
    : _windowName{std::string{windowName}}, _windowSize{windowSize},
    _window{irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(_windowSize.x, _windowSize.y), 16, false, false, false, nullptr)},
    _videoDrivers{_window->getVideoDriver()},
    _sceneManager{_window->getSceneManager()},
    _GUIEnvironment{_window->getGUIEnvironment()}
{
    _window->setWindowCaption(std::wstring{_windowName.begin(), _windowName.end()}.c_str());
}

Engine::ECS::System::Renderer::~Renderer()
{
    _window->drop();
}

void Engine::ECS::System::Renderer::update(double)
{
    throw NotImplementedException{"Engine::ECS::System::Renderer::update"};
}
