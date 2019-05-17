/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** Chrono.hpp
*/

#pragma once

#include <chrono>

#include "ECS/Abstracts/AComponent.hpp"

namespace Engine {
    namespace Component {
        class Chrono;
    }
}

class Engine::Component::Chrono : public Engine::ECS::AComponent {
public:
    double getElapsedTime() const noexcept;
    void reset() noexcept;

private:
    std::chrono::_V2::system_clock::time_point _start{std::chrono::system_clock::now()};
};
