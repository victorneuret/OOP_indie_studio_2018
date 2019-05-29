/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Chrono.hpp
*/

#pragma once

#include <chrono>

#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::Component {
    class Chrono;
}

class Engine::Component::Chrono : public Engine::ECS::AComponent<Engine::Component::Chrono> {
public:
    Chrono();

    double getElapsedTime() noexcept;
    void reset() noexcept;

private:
    std::chrono::time_point<std::chrono::system_clock> _start{std::chrono::system_clock::now()};
    std::chrono::duration<double> _elapsedTime = _start - _start;
};
