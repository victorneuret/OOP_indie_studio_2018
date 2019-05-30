/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <memory>
#include <irrlicht/irrlicht.h>

#include "ECS/Systems/Renderer.hpp"
#include "Exception/NotImplementedException.hpp"

Engine::ECS::System::Renderer::Renderer(const std::wstring &windowName, const Engine::Math::Vec2u &windowSize)
    : _windowName{windowName}, _windowSize{windowSize},
    _window{irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(_windowSize.x, _windowSize.y), 16, false, false, false, nullptr)},
    _videoDrivers{_window->getVideoDriver()},
    _sceneManager{_window->getSceneManager()},
    _GUIEnvironment{_window->getGUIEnvironment()}
{
    _window->setWindowCaption(_windowName.c_str());
    _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100, 0, 0), irr::core::vector3df(0, 0, 0));
}

Engine::ECS::System::Renderer::~Renderer()
{
    _window->drop();
}

void Engine::ECS::System::Renderer::update(double)
{
    _videoDrivers->endScene();
}

irr::scene::IAnimatedMeshSceneNode *Engine::ECS::System::Renderer::create3DModel(const std::string &model)
{
    auto *mesh = _sceneManager->getMesh(model.c_str());
    return _sceneManager->addAnimatedMeshSceneNode(mesh);
}

irr::gui::IGUIFont *Engine::ECS::System::Renderer::createFont(const std::string &fontPath)
{
    if (fontPath.empty())
        return _window->getGUIEnvironment()->getBuiltInFont();
    return _window->getGUIEnvironment()->getFont(fontPath.c_str());
}

bool Engine::ECS::System::Renderer::closeRequested() const noexcept
{
    return !_window->run();
}

void Engine::ECS::System::Renderer::draw(Engine::ECS::Component::Renderer *renderer)
{
    switch (renderer->getType()) {
        case Component::Renderer::type::TEXT:
            renderer->getFont()->draw(renderer->getText().c_str(), irr::core::rect<irr::s32>(renderer->getPosition().x, renderer->getPosition().y, 200, 22), irr::video::SColor(renderer->getColor().a, renderer->getColor().r, renderer->getColor().g, renderer->getColor().b));
            break;
        default:
            break;
    }
}

void Engine::ECS::System::Renderer::refresh()
{
    _videoDrivers->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
}

void Engine::ECS::System::Renderer::show(Engine::ECS::Component::Renderer *)
{
    throw NotImplementedException{"Engine::ECS::System::Renderer::show"};
}

void Engine::ECS::System::Renderer::hide(Engine::ECS::Component::Renderer *renderer)
{
    renderer->getNode()->remove();
}
