/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Input
*/

#pragma once

#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::System {
    class KeyboardInput;
}

class Engine::ECS::System::KeyboardInput final : public Engine::ECS::System::AInput {
public:
    KeyboardInput();
    bool OnEvent(irr::SEvent &event) final;
};
