/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.hpp
*/

#pragma once

#include "Abstracts/AScene.hpp"

namespace Game::Scene {
    class MainMenu;
}

class Game::Scene::MainMenu final : public Engine::Abstracts::AScene {
public:
    explicit MainMenu();

    MainMenu(const MainMenu &) = delete;
    MainMenu &operator=(const MainMenu &) = delete;

    void tick(double deltaTime) override;
};
