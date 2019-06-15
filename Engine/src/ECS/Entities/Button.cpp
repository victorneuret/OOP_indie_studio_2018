/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Button.cpp
*/

#include "ECS/Entities/Button.hpp"
#include "ECS/Components/Text.hpp"
#include "ECS/Components/Button.hpp"
#include "Math/Vector/Vec2.hpp"


Engine::ECS::Entity::Button::Button(const Engine::Math::Rect_i &bounds, const std::string &imagePath, const std::function<void()> &func)
    : AEntity(AEntity::Type::BUTTON)
{
    std::shared_ptr<Engine::ECS::IComponent> button = std::make_shared<Engine::ECS::Component::Button>(bounds, imagePath, func);
    addComponent(button);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}

bool Engine::ECS::Entity::Button::onEvent(irr::gui::EGUI_EVENT_TYPE eventType)
{
    if (eventType == irr::gui::EGET_BUTTON_CLICKED)
        std::dynamic_pointer_cast<Engine::ECS::Component::Button>(getComponentByID("Button"))->onClick();
    return false;
}
