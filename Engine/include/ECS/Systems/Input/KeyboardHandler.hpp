/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KeyboardHandler.hpp
*/

#pragma once

#include <map>
#include <functional>
#include <irrlicht/irrlicht.h>

#include "Math/Vector/Vec2.hpp"
#include "ECS/Interfaces/InputType.hpp"

namespace Engine::ECS::System {
    class KeyboardHandler;
}

class Engine::ECS::System::KeyboardHandler final : public InputType {
protected:
    const std::map<INPUT_KEY, std::function<bool()>> _buttons = {
        {B_PRIMARY,    [&]() { return isButtonPressed(irr::KEY_SPACE); }},
        {B_START,  [&]() { return isButtonPressed(irr::KEY_ESCAPE); }}
    };

    bool isButtonPressed(irr::EKEY_CODE) const;

public:
    KeyboardHandler() = default;
    ~KeyboardHandler() override = default;

    Engine::Math::Vec2f getPosition() const override;
    bool isKeyDown(irr::u8 key) const override;
};