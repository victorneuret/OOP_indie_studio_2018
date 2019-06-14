/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KeyboardHandler.hpp
*/

#pragma once

#include <map>
#include <functional>

#include "irrlicht.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Interfaces/InputType.hpp"

namespace Game::System {
    class KeyboardHandler;
}

class Game::System::KeyboardHandler final : public Engine::ECS::InputType {
protected:
    const std::map<INPUT_KEY, std::function<bool()>> _buttons = {
        {B_PRIMARY,    [&]() { return isButtonPressed(irr::KEY_KEY_X); }},
        {B_START,  [&]() { return isButtonPressed(irr::KEY_KEY_X); }}
    };

    bool isButtonPressed(irr::EKEY_CODE) const;

public:
    KeyboardHandler() = default;
    ~KeyboardHandler() override = default;

    Engine::Math::Vec2f getPosition() const override;
    bool isKeyDown(irr::u8 key) const override;
};
