/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** Chrono.hpp
*/

#pragma once

#include <chrono>
#include "Abstracts/AComponent.hpp"

namespace Engine {
    namespace Component {
        class Chrono;
    }
}

class Engine::Component::Chrono : public Engine::ECS::AComponent {
public:
    Chrono(const size_t id);

    double getElapsedTime() const noexcept;

    void reset() noexcept;

private:
    std::chrono::_V2::system_clock::time_point _start;
};