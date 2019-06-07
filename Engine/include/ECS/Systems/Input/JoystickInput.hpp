/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** JoystickInput
*/

#pragma once

#include <map>
#include <vector>
#include <memory>
#include <irrlicht/irrlicht.h>

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::System {
    class JoystickInput;
}

struct Controller {
    irr::u16 POV;
    irr::s16 Axis[irr::SEvent::SJoystickEvent::NUMBER_OF_AXES];
    irr::u32 ButtonStates;
};

class Engine::ECS::System::JoystickInput final : public AInput {
protected:
    std::map<irr::u8, Controller> _controllers{};

public:
    explicit JoystickInput();

    bool OnEvent(const irr::SEvent &event) override;
    // const std::remove_all_extents<decltype(_axis)>::type &getAxis(irr::u8 axis);
};
