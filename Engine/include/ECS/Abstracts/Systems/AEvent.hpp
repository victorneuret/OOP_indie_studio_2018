/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AEvent
*/

#pragma once

#include <map>
#include <algorithm>
#include <irrlicht/irrlicht.h>

#include "ECS/Abstracts/AComponent.hpp"
#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class AEvent;
}

class Engine::ECS::System::AEvent : public ASystem, public irr::IEventReceiver {
public:
    explicit AEvent(const std::string &id);
};
