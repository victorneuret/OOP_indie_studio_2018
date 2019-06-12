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
#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class AInput;
}

class Engine::ECS::System::AInput : public Engine::ECS::ASystem, public irr::IEventReceiver {
protected:
    std::map<decltype(irr::SEvent::SKeyInput::Char), bool> _keys{};

public:
    explicit AInput(const std::string &id) : ASystem{id} {}
    ~AInput() override = default;

    bool OnEvent(const irr::SEvent &) override = 0;

    decltype(_keys)::value_type::second_type isKeyDown(const decltype(irr::SEvent::SKeyInput::Char) key)
    {
        if (_keys.find(key) != _keys.end())
            return _keys[key];
        return false;
    }
};
