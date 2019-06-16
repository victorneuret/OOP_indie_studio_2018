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
private:
    bool _pauseLock{true};
public:
    PauseMenu();

    PauseMenu(const PauseMenu &) = delete;
    PauseMenu &operator=(const PauseMenu &) = delete;

    void tick(double deltaTime) override;
    void sceneShowing() override;
    void sceneHiding(const AScene *newParent) override;
};
