/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** IGUIElement.hpp
*/

#pragma once

#if defined _MSC_VER
    #include <irrlicht.h>
#elif defined __GNUC__
    #include <irrlicht/irrlicht.h>
#endif

namespace Engine::ECS::Entity {
    class IGuiElement;
}

class Engine::ECS::Entity::IGuiElement {
protected:
    static irr::s32 GLOBAL_ID;
    const decltype(GLOBAL_ID) _guiID{++GLOBAL_ID};

public:
    virtual ~IGuiElement() = default;

    virtual bool onEvent(irr::gui::EGUI_EVENT_TYPE eventType) = 0;
    const decltype(_guiID) &getGuiID() const;
};
