/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** JoystickInput
*/

#pragma once

#if defined _MSC_VER
    #include <irrlicht.h>
#elif defined __GNUC__
    #include <irrlicht/irrlicht.h>
#endif

#include <type_traits>
#include <map>
#include <vector>
#include <memory>
#include <type_traits>

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
    irr::core::array<irr::SJoystickInfo> _joystickInfos{};

public:
    JoystickInput();
    ~JoystickInput() override = default;

    bool OnEvent(const irr::SEvent &event) override;
    bool isKeyDown(irr::u8 controller, irr::u8 key) const;

    const decltype(_joystickInfos) &getJoystickInfos() const noexcept;
    irr::u16 getPov(irr::u8 controller) const noexcept ;
    irr::s16 getAxis(irr::u8 controller, irr::u8 axis) const noexcept;

};
