/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EventHandler.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <irrlicht/irrlicht.h>

#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class EventHandler;

    constexpr const char *TYPE_STR = "EventHandler";
}

class Engine::ECS::System::EventHandler : public ASystem<EventHandler> {
protected:
    std::vector<irr::IEventReceiver *> _handlers{};

public:
    EventHandler();

    void add(irr::IEventReceiver *handler);
    bool OnEvent(const irr::SEvent &event);
};