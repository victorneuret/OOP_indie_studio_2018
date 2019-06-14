/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PauseMenu.hpp
*/

#pragma once

#include "Abstracts/AScene.hpp"

namespace Game::Scene {
    class PauseMenu;
}

class Game::Scene::PauseMenu final : public Engine::Abstracts::AScene {
public:
    PauseMenu();

    PauseMenu(const PauseMenu &) = delete;
    PauseMenu &operator=(const PauseMenu &) = delete;

    void tick(double deltaTime) override;
};
