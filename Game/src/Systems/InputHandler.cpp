/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** InputHandler.hpp.cpp
*/

#include <exception>

#include "ECS/Manager.hpp"
#include "Entities/Character.hpp"
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

void Engine::ECS::System::InputHandler::update(double dt)
{
    try {
        auto game = Engine::ECS::Manager::getInstance().getSceneByID("Game");

        for (const auto &c : _inputs) {
            auto player = std::dynamic_pointer_cast<Game::Entity::Character>(game->getEntityByID(c.first));

            if (player == nullptr)
                continue;

            player->move(c.second->getPosition(), dt);

            if (c.second->isKeyDown(Engine::ECS::InputType::B_PRIMARY))
                player->placeBomb();
        }
    } catch (...) {}
}
