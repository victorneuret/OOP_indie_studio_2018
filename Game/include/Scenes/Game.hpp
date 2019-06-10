/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Game.hpp.cpp
*/

#pragma once

#include "Abstracts/AScene.hpp"

namespace Game::Scene {
    class Game;
}

class Game::Scene::Game final : public Engine::Abstracts::AScene {
public:
    Game();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    void tick(double deltaTime) override;
};