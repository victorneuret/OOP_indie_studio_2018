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

class Engine::ECS::System::AInput : public ASystem, public irr::IEventReceiver {
protected:
    std::map<decltype(irr::SEvent::SKeyInput::Char), bool> _keys{};

public:
    explicit AInput(const std::string &id);
    ~AInput() override = default;

    void update(double) final;
};
