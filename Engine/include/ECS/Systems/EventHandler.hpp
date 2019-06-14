/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EventHandler.hpp
*/

#pragma once

#if defined _MSC_VER
    #include <irrlicht.h>
#elif defined __GNUC__
    #include <irrlicht/irrlicht.h>
#endif

#include <vector>
#include <memory>

#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class EventHandler;

    constexpr const char *TYPE_STR = "EventHandler";
}

class Engine::ECS::System::EventHandler final : public ASystem, public irr::IEventReceiver {
protected:
    std::vector<irr::IEventReceiver *> _handlers{};

public:
    EventHandler();
    ~EventHandler() override = default;

    void add(irr::IEventReceiver *handler);
    bool OnEvent(const irr::SEvent &event) override;
    void update(double dt) override;
};
