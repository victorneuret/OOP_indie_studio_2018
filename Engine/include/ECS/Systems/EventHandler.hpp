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

class Engine::ECS::System::EventHandler : public ASystem<EventHandler> {
protected:
    std::vector<std::shared_ptr<irr::IEventReceiver>> _middlewares{};

public:

};