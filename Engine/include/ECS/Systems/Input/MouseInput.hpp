/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MouseInput
*/

#pragma once

#include <irrlicht/IEventReceiver.h>

#include "ECS/Abstracts/Systems/AInput.hpp"
#include "Math/Vector/Vec2.hpp"

namespace Engine::ECS::System {
    class MouseInput;
}

class Engine::ECS::System::MouseInput final : public Engine::ECS::System::AInput {
private:
    enum MouseKey {
        LEFT,
        RIGHT,
        MIDDLE
    };

    Engine::Math::Vec2<decltype(irr::SEvent::SMouseInput::X)> _pos{};
    std::map<MouseKey, bool> _keys{};

public:
    MouseInput();

    bool OnEvent(const irr::SEvent &event) override;
    bool isKeyDown(MouseKey key) const;
    const decltype(_pos) &pos() const noexcept;
};
