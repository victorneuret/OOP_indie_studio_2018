/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ButtonEvent.hpp
*/

#pragma once

#include "ECS/Abstracts/Systems/AEvent.hpp"

namespace Engine::ECS::System {
    class ButtonEvent;
}

class Engine::ECS::System::ButtonEvent final : public Engine::ECS::System::AEvent {
public:
    ButtonEvent();

    bool OnEvent(const irr::SEvent &event) override;
    void update(double dt) override;
};
