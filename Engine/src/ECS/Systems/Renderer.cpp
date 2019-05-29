/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <irrlicht/irrlicht.h>
#include <memory>

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
    _videoDrivers->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
    _sceneManager->drawAll();
    _GUIEnvironment->drawAll();
    _videoDrivers->endScene();
}

irr::scene::IAnimatedMeshSceneNode *Engine::ECS::System::Renderer::create3DModel(const std::string &model)
{
    auto *mesh = _sceneManager->getMesh(model.c_str());
    return _sceneManager->addAnimatedMeshSceneNode(mesh);
}

bool Engine::ECS::System::Renderer::closeRequested() const noexcept
{
    return !_window->run();
}

void Engine::ECS::System::Renderer::draw(Engine::ECS::Component::Renderer *renderer)
{
    switch (renderer->getType()) {
        case Component::Renderer::type::MODEL3D:
            renderer->getNode()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            renderer->getNode()->setFrameLoop(0, 310);
            renderer->getNode()->setMaterialTexture(0, _videoDrivers->getTexture(renderer->getTexture().c_str()));
            break;
        default:
            break;
    }
}