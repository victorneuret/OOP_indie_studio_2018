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
#include "ECS/Components/Button.hpp"
#include "ECS/Components/Model3D.hpp"
#include "ECS/Components/Renderer.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/NotImplementedException.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

Engine::ECS::System::Renderer::Renderer(const decltype(_windowName) &windowName, const decltype(_windowSize) &windowSize)
    : _windowName{std::wstring{windowName}}, _windowSize{windowSize},
    _window{irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(_windowSize.x, _windowSize.y), 16, false, false, false, nullptr)},
    _videoDrivers{_window->getVideoDriver()},
    _sceneManager{_window->getSceneManager()},
    _GUIEnvironment{_window->getGUIEnvironment()}
{
    if (_window == nullptr || _videoDrivers == nullptr || _sceneManager == nullptr || _GUIEnvironment == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to initialise the window"};
    _window->setWindowCaption(_windowName.c_str());
    _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100, 0, 0), irr::core::vector3df(0, 0, 0));
}

Engine::ECS::System::Renderer::~Renderer()
{
    _window->drop();
}

void Engine::ECS::System::Renderer::update(double)
{
    _GUIEnvironment->drawAll();
    _sceneManager->drawAll();
    if (!_videoDrivers->endScene())
        throw ECSException<ECS_Renderer>{"Display error"};
}

irr::scene::IAnimatedMeshSceneNode *Engine::ECS::System::Renderer::create3DModel(const std::string &model, const std::string &texture) const
{
    auto mesh = _sceneManager->getMesh(model.c_str());
    if (mesh == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to create Mesh"};
    auto animatedMesh = _sceneManager->addAnimatedMeshSceneNode(mesh);
    if (animatedMesh == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to create animated Mesh"};
    animatedMesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    animatedMesh->setMaterialTexture(0, _videoDrivers->getTexture(texture.c_str()));
    animatedMesh->setPosition(irr::core::vector3df{0, 0, 0});
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

irr::gui::IGUIButton *Engine::ECS::System::Renderer::createButton(const Engine::Math::Rect_i &pos, const std::wstring &text) const
{
    auto button = _GUIEnvironment->addButton(irr::core::rect<irr::s32>{pos.x, pos.y, pos.x + pos.w, pos.y + pos.h});
    if (button == nullptr)
        throw ECSException<ECS_Renderer>{"Failed to create the button"};
    button->setText(text.c_str());
    return button;
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
        default:
            break;
    }
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
    button->getButton()->setVisible(renderer->doRender());
}

void Engine::ECS::System::Renderer::refresh() const
{
    if (!_videoDrivers->beginScene(true, true, irr::video::SColor(0, 0, 0, 0)))
        throw ECSException<ECS_Renderer>{"Display error"};
}
