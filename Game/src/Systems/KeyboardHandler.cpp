/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** KeyboardHandler.cpp
*/

#include <memory>
#include <functional>

#include "ECS/Manager.hpp"
#include "Math/Vector/Vec2.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "Systems/KeyboardHandler.hpp"

bool Game::System::KeyboardHandler::isButtonPressed(irr::EKEY_CODE key) const
{
    const auto input = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(
        Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));

    if (input == nullptr)
        return false;

    return input->isKeyDown(key);
}

Engine::Math::Vec2f Game::System::KeyboardHandler::getPosition() const
{
    const auto &input = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(
        Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));

    auto x = (input->isKeyDown(irr::KEY_LEFT) + input->isKeyDown(irr::KEY_KEY_Q)) -
        (input->isKeyDown(irr::KEY_RIGHT) + input->isKeyDown(irr::KEY_KEY_D));
    auto y = (input->isKeyDown(irr::KEY_DOWN) + input->isKeyDown(irr::KEY_KEY_S)) -
        (input->isKeyDown(irr::KEY_UP) + input->isKeyDown(irr::KEY_KEY_Z));

    return {
        x < -1.f ? -1.f : x > 1.f ? 1.f : x,
        y < -1.f ? -1.f : y > 1.f ? 1.f : y
    };
}

bool Game::System::KeyboardHandler::isKeyDown(irr::u8 key) const
{
    const auto &input = std::dynamic_pointer_cast<Engine::ECS::System::KeyboardInput>(
        Engine::ECS::Manager::getInstance().getSystemByID("KeyboardInput"));

    if (input == nullptr)
        return false;

    for (unsigned i = 0; i < sizeof(key) * 8; i++) {
        if (key & (1u << i)) {
            auto func = _buttons.find(static_cast<INPUT_KEY>(key & (1u << i)));

            if (func == _buttons.end() || !func->second())
                return false;
        }
    }
    return true;
}
