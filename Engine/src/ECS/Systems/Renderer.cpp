/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <memory>
#include <irrlicht/irrlicht.h>

#include "ECS/Components/Text.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/NotImplementedException.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::ECS::System::Renderer::Renderer(const std::wstring &windowName, const Engine::Math::Vec2u &windowSize)
    : _windowName{windowName}, _windowSize{windowSize},
    _window{irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(_windowSize.x, _windowSize.y), 16, false, false, false, nullptr)},
    _videoDrivers{_window->getVideoDriver()},
    _sceneManager{_window->getSceneManager()},
    _GUIEnvironment{_window->getGUIEnvironment()}
{
    if (_window == nullptr || _videoDrivers == nullptr || _sceneManager == nullptr || _GUIEnvironment == nullptr)
        throw MemoryException<Memory_Allocation_Failed>{"Failed to initialise the window"};
    _window->setWindowCaption(_windowName.c_str());
    _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100, 0, 0), irr::core::vector3df(0, 0, 0));
}

Engine::ECS::System::Renderer::~Renderer()
{
    _window->drop();
}

void Engine::ECS::System::Renderer::update(double)
{
    if (!_videoDrivers->endScene())
        throw ECSException<ECS_System>{"Display error"};
}

irr::scene::IAnimatedMeshSceneNode *Engine::ECS::System::Renderer::create3DModel(const std::string &model) const
{
    auto *mesh = _sceneManager->getMesh(model.c_str());
    if (mesh == nullptr)
        throw MemoryException<Memory_Allocation_Failed>{"Failed to create Mesh"};
    return _sceneManager->addAnimatedMeshSceneNode(mesh);
}

irr::gui::IGUIFont *Engine::ECS::System::Renderer::createFont(const std::string &fontPath) const
{
    irr::gui::IGUIFont *font{nullptr};

    if (fontPath.empty())
        font =  _window->getGUIEnvironment()->getBuiltInFont();
    else
        font =  _window->getGUIEnvironment()->getFont(fontPath.c_str());
    if (font == nullptr)
        throw MemoryException<Memory_Allocation_Failed>{"Failed to initialise the window"};
    return font;
}

bool Engine::ECS::System::Renderer::closeRequested() const noexcept
{
    return !_window->run();
}

void Engine::ECS::System::Renderer::draw(std::shared_ptr<Engine::ECS::IEntity> entity) const
{
    switch (entity->getType()) {
        case Engine::ECS::IEntity::Type::TEXT:
            drawText(entity);
        default:
            break;
    }
}

void Engine::ECS::System::Renderer::drawText(std::shared_ptr<Engine::ECS::IEntity> entity) const
{
    std::shared_ptr<Engine::ECS::Component::Text> _component = std::dynamic_pointer_cast<Engine::ECS::Component::Text> (entity->getComponentByID("Text"));

    _component->getFont()->draw(_component->getString().c_str(), irr::core::rect<irr::s32>{_component->getPos().x, _component->getPos().y, 300, 50}, irr::video::SColor{_component->getColor().a, _component->getColor().r, _component->getColor().g, _component->getColor().b});
}

void Engine::ECS::System::Renderer::refresh() const
{
    if (!_videoDrivers->beginScene(true, true, irr::video::SColor(0, 0, 0, 0)))
        throw ECSException<ECS_System>{"Display error"};
}

void Engine::ECS::System::Renderer::show(std::shared_ptr<Engine::ECS::IEntity>) const
{
    // renderer->setDoRender(true);
}

void Engine::ECS::System::Renderer::hide(std::shared_ptr<Engine::ECS::IEntity>) const
{
    // renderer->setDoRender(false);
}
