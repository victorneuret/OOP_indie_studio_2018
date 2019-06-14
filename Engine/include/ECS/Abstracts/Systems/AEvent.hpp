/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AEvent
*/

#pragma once

#if defined _MSC_VER
    #include <irrlicht.h>
#elif defined __GNUC__
    #include <irrlicht/irrlicht.h>
#endif

#include <map>
#include <algorithm>

#include "ECS/Abstracts/AComponent.hpp"
#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class AEvent;
}

class Engine::ECS::System::AEvent : public ASystem, public irr::IEventReceiver {
public:
    explicit AEvent(const std::string &id);
};
