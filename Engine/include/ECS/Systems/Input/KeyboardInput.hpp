/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Input
*/

#pragma once

#include <map>
#include <irrlicht/irrlicht.h>

#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::System {
    class KeyboardInput;
}

class Engine::ECS::System::KeyboardInput final : public AInput {
protected:
    std::map<irr::EKEY_CODE, bool> _keys{};

public:
    KeyboardInput();
    ~KeyboardInput() override = default;

    bool OnEvent(const irr::SEvent &event) override;
    bool isKeyDown(irr::EKEY_CODE key) const;
};
