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
}

class Engine::ECS::System::EventHandler final : public ASystem<EventHandler>, public irr::IEventReceiver {
protected:
    std::vector<irr::IEventReceiver *> _handlers{};

public:
    EventHandler();
    ~EventHandler() override = default;

    void add(irr::IEventReceiver *handler);
    bool OnEvent(const irr::SEvent &event) override;
    void update(double dt) override;
};
