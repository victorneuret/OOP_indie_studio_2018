/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** JoystickInput
*/

#pragma once

#include <type_traits>
#include <map>
#include <vector>
#include <memory>
#include <type_traits>
#include <irrlicht/irrlicht.h>

#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::System {
    class JoystickInput;
}

struct Controller {
    irr::u16 pov;
    irr::s16 axis[irr::SEvent::SJoystickEvent::NUMBER_OF_AXES];
    irr::u32 buttonStates;
};

class Engine::ECS::System::JoystickInput final : public AInput {
protected:
    std::map<irr::u8, Controller> _controllers{};

public:
    JoystickInput();
    ~JoystickInput() override = default;

    void update(double) override;
    bool OnEvent(const irr::SEvent &event) final;
};
