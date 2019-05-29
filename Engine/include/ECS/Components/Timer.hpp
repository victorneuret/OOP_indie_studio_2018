/*
** EPITECH PROJECT, 2019    
** bomberman
** File description:
** Timer.hpp
*/

#pragma once


#include <chrono>
#include <functional>
#include <thread>
#include <memory>

#include "ECS/Abstracts/AComponent.hpp"

namespace Engine::Component {
    class Timer;
}

class Engine::Component::Timer : public Engine::ECS::AComponent<Engine::Component::Timer> {
public:
    Timer();

    void cooldown(const double &duration, const std::function<void()> &func);

private:
    std::unique_ptr<std::thread> _thread{nullptr};
};
