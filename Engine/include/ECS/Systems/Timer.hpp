/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Timer.hpp
*/

#pragma once

#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class Timer;
}

class Engine::ECS::System::Timer final : public ASystem {
private:

public:
    explicit Timer();
    Timer &operator=(const Timer &) = delete;
    Timer(const Timer &) = delete;
    ~Timer() override = default;

    void update(double dt) override;
};
