/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ButtonEvent.cpp
*/

#include "ECS/Manager.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "ECS/Interfaces/Entities/IGuiElement.hpp"
#include "ECS/Systems/Event/ButtonEvent.hpp"

Engine::ECS::System::ButtonEvent::ButtonEvent()
    : AEvent{"ButtonEvent"}
{}

bool Engine::ECS::System::ButtonEvent::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        const auto ID = event.GUIEvent.Caller->getID();

        for (auto &scene : Engine::ECS::Manager::getInstance().getScenes()) {
            for (auto &c : scene->getEntities()) {
                if (c == nullptr || c->getType() != IEntity::Type::BUTTON || event.GUIEvent.EventType != irr::gui::EGUI_EVENT_TYPE::EGET_BUTTON_CLICKED)
                    continue;

                auto guiElement = std::dynamic_pointer_cast<Entity::IGuiElement>(c);

                if (guiElement && ID == static_cast<int>(guiElement->getGuiID())) {
                    if (guiElement->onEvent(event.GUIEvent.EventType))
                        return true;
                }
            }
        }
    }
    return false;
}

void Engine::ECS::System::ButtonEvent::update(double)
{}
