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

#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class AInput;
}

class Engine::ECS::System::AInput : public Engine::ECS::ASystem<Engine::ECS::System::AInput>, public irr::IEventReceiver {
protected:
    std::map<decltype(irr::SEvent::SKeyInput::Char), bool> _keys{};

public:
    explicit AInput(const std::string &id) : ASystem{id} {}
    virtual ~AInput() override = default;

    virtual bool OnEvent(irr::SEvent &) = 0;

    decltype(_keys)::value_type::second_type isKeyDown(const decltype(irr::SEvent::SKeyInput::Char) key)
    {
        if (_keys.find(key) != _keys.end())
            return _keys[key];
        return false;
    }
};
