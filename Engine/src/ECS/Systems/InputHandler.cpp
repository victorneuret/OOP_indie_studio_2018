/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** InputHandler.hpp.cpp
*/

#include <iostream>

#include "ECS/Manager.hpp"
#include "ECS/Systems/Input/KeyboardInput.hpp"
#include "ECS/Systems/Input/JoystickInput.hpp"
#include "ECS/Systems/InputHandler.hpp"

Engine::ECS::System::InputHandler::InputHandler()
    : ASystem{"InputHandler"}
{}

void Engine::ECS::System::InputHandler::bind(size_t id, const std::shared_ptr<InputType> &input)
{
    _inputs[id] = input;
}

bool Engine::ECS::System::InputHandler::isKeyPressed(size_t id, Engine::ECS::InputType::INPUT_KEY)
{
    const auto input = _inputs.find(id);

    if (input == _inputs.end())
        return false;

    return false;
}

void Engine::ECS::System::InputHandler::update(double)
{
    std::cout << "START:" << std::endl;
    for (const auto &c : _inputs) {
        std::cout << "X: " << c.second->getPosition().x << " Y: " << c.second->getPosition().y << std::endl;
    }
    std::cout << "END" << std::endl;
}