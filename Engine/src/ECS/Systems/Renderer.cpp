/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Renderer.cpp
*/

#include <memory>
#include <iostream>
#include <irrlicht/irrlicht.h>

#include "ECS/Components/Text.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Components/Button.hpp"
#include "ECS/Components/Image.hpp"
#include "ECS/Components/Slider.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

bool Engine::ECS::System::Renderer::EventMiddleware::OnEvent(const irr::SEvent &event)
{
    for (auto &h : _handlers) {
        if (h->OnEvent(event))
            return true;
    }
    return false;
}

void Engine::ECS::System::Renderer::EventMiddleware::addEventHandler(const std::shared_ptr<irr::IEventReceiver> &handler)
{
    _handlers.push_back(handler);
}

Engine::ECS::System::Renderer::Renderer(const decltype(_windowName) &windowName, const decltype(_windowSize) &windowSize)
    : ASystem{"Renderer"},
    _windowName{std::wstring{windowName}}, _windowSize{windowSize},
    _window{irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(_windowSize.x, _windowSize.y), 16, false, false, false, nullptr)},
    _videoDriver{_window->getVideoDriver()},
    _sceneManager{_window->getSceneManager()},
    _GUIEnvironment{_window->getGUIEnvironment()}
{
    if (_window == nullptr || _videoDriver == nullptr || _sceneManager == nullptr || _GUIEnvironment == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to initialise the window"};
    _window->setWindowCaption(_windowName.c_str());

    irr::core::array<irr::SJoystickInfo> joystickInfo;
    if (!_window->activateJoysticks(joystickInfo)) {
        std::cerr << "Joystick support is not enabled." << std::endl;
    }
}

Engine::ECS::System::Renderer::~Renderer()
{
    _window->drop();
}

void Engine::ECS::System::Renderer::update(double)
{
    _GUIEnvironment->drawAll();
    _sceneManager->drawAll();
    if (!_videoDriver->endScene())
        throw ECSException<ECS_Renderer>{"Display error"};
}

irr::scene::IAnimatedMeshSceneNode *Engine::ECS::System::Renderer::create3DModel(const std::string &model) const
{
    auto mesh = _sceneManager->getMesh(model.c_str());
    if (mesh == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to create Mesh"};
    auto animatedMesh = _sceneManager->addAnimatedMeshSceneNode(mesh);
    if (animatedMesh == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to create animated Mesh"};
    animatedMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    animatedMesh->setFrameLoop(0, 4000);
    animatedMesh->setVisible(true);
    return animatedMesh;
}

irr::gui::IGUIFont *Engine::ECS::System::Renderer::createFont(const std::string &fontPath) const
{
    irr::gui::IGUIFont *font{nullptr};

    if (fontPath.empty())
        font = _window->getGUIEnvironment()->getBuiltInFont();
    else
        font = _window->getGUIEnvironment()->getFont(fontPath.c_str());
    if (font == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to create the font"};
    return font;
}

bool Engine::ECS::System::Renderer::closeRequested() const noexcept
{
    return !_window->run();
}

void Engine::ECS::System::Renderer::draw(const std::shared_ptr<Engine::ECS::IEntity> &entity) const
{
    switch (entity->getType()) {
        case Engine::ECS::IEntity::Type::TEXT:
            drawText(entity);
            break;
        case Engine::ECS::IEntity::Type::MODEL3D:
            draw3DModel(entity);
            break;
        case Engine::ECS::IEntity::Type::BUTTON:
            drawButton(entity);
            drawText(entity);
            break;
        case Engine::ECS::IEntity::Type::SLIDER:
            drawSlider(entity);
            break;
        case Engine::ECS::IEntity::Type::MODEL2D:
            drawImage(entity);
            break;
        default:
            break;
    }
}

void Engine::ECS::System::Renderer::drawRectangle(const Engine::Math::Rect_i &pos, const Engine::Utils::Color &color) const
{
    _videoDriver->draw2DRectangle(irr::video::SColor{color.a, color.r, color.g, color.b}, irr::core::rect<irr::s32>{pos.x, pos.y, pos.x + pos.w, pos.y + pos.h});
}

void Engine::ECS::System::Renderer::drawText(const std::shared_ptr<Engine::ECS::IEntity> &entity) const
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::Component::Renderer>(entity->getComponentByID("Renderer"));
    auto text = std::dynamic_pointer_cast<Engine::ECS::Component::Text>(entity->getComponentByID("Text"));
    if (renderer->doRender())
        text->getFont()->draw(text->getString().c_str(), irr::core::rect<irr::s32>{text->getPos().x, text->getPos().y, 300, 50}, irr::video::SColor{text->getColor().a, text->getColor().r, text->getColor().g, text->getColor().b});
}

void Engine::ECS::System::Renderer::draw3DModel(const std::shared_ptr<Engine::ECS::IEntity> &entity) const
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::Component::Renderer>(entity->getComponentByID("Renderer"));
    auto model = std::dynamic_pointer_cast<Engine::ECS::Component::Model3D>(entity->getComponentByID("Model3D"));
    model->getNode()->setVisible(renderer->doRender());
}

void Engine::ECS::System::Renderer::drawButton(const std::shared_ptr<Engine::ECS::IEntity> &entity) const
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::Component::Renderer>(entity->getComponentByID("Renderer"));
    auto button = std::dynamic_pointer_cast<Engine::ECS::Component::Button>(entity->getComponentByID("Button"));
    if (renderer->doRender())
        drawRectangle(button->getBounds(), button->getColor());
}

void Engine::ECS::System::Renderer::drawSlider(const std::shared_ptr<Engine::ECS::IEntity> &entity) const
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::Component::Renderer>(entity->getComponentByID("Renderer"));
    auto slider = std::dynamic_pointer_cast<Engine::ECS::Component::Slider>(entity->getComponentByID("Slider"));
    if (renderer->doRender()) {
        drawRectangle(slider->getBounds(), slider->getBackgroundColor());
        auto bounds = Math::Rect_i{slider->getBounds().x, slider->getBounds().y, slider->getValue(), slider->getBounds().h};
        drawRectangle(bounds, slider->getValueColor());
    }
}

void Engine::ECS::System::Renderer::drawImage(const std::shared_ptr<Engine::ECS::IEntity> &entity) const
{
    auto renderer = std::dynamic_pointer_cast<Engine::ECS::Component::Renderer>(entity->getComponentByID("Renderer"));
    auto image = std::dynamic_pointer_cast<Engine::ECS::Component::Image>(entity->getComponentByID("Image"));

    if (renderer->doRender()) {
        image->getGUIImage()->setMaxSize(irr::core::dimension2du{image->getSize().x, image->getSize().y});
        image->getGUIImage()->setMinSize(irr::core::dimension2du{image->getSize().x, image->getSize().y});
    }
}

void Engine::ECS::System::Renderer::refresh() const
{
    if (!_videoDriver->beginScene(true, true, irr::video::SColor(0, 0, 0, 0)))
        throw ECSException<ECS_Renderer>{"Display error"};
}

decltype(Engine::ECS::System::Renderer::_videoDriver) Engine::ECS::System::Renderer::getVideoDriver() const noexcept
{
    return _videoDriver;
}

decltype(Engine::ECS::System::Renderer::_sceneManager) Engine::ECS::System::Renderer::getSceneManager() const noexcept
{
    return _sceneManager;
}

decltype(Engine::ECS::System::Renderer::_GUIEnvironment) Engine::ECS::System::Renderer::getGUIEnvironment() const noexcept
{
    return _GUIEnvironment;
}
