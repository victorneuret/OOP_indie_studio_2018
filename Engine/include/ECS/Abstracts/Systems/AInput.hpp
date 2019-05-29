/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AInput
*/

#pragma once

#include <map>
#include <algorithm>
#include <irrlicht/irrlicht.h>

#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::ECS::Systems {
    class AInput;
}

class Engine::ECS::Systems::AInput : public Engine::ECS::AComponent<Engine::ECS::Systems::AInput>, irr::IEventReceiver {
protected:
    std::map<decltype(irr::SEvent::SKeyInput::Char), bool> _keys;

public:
    virtual ~AInput() override = default;

    virtual bool OnEvent(irr::SEvent &) = 0;

    decltype(_keys)::value_type::second_type isKeyDown(const uint8_t key)
    {
        if (_keys.find(key) != _keys.end())
            return _keys[key];
        return false;
    }
};