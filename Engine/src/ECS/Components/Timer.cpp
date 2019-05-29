/*
** EPITECH PROJECT, 2019    
** bomberman
** File description:
** Timer.cpp
*/

#include <iostream>

#include "ECS/Components/Timer.hpp"
#include "ECS/Components/Chrono.hpp"

void Engine::Component::Timer::cooldown(const double &duration, const std::function<void()> &func) {
    _thread = std::make_unique<std::thread>([duration, func]() {
        Chrono timer;

        std::cout << timer.getElapsedTime() << " | " << duration << std::endl;
        while (timer.getElapsedTime() < duration);
        func();
    });
}