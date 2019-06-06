/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.hpp
*/

#pragma once

#include "AScene.hpp"

namespace Engine::Scene {
    class MainMenu;
}

class Engine::Scene::MainMenu final : public AScene {
public:
    explicit MainMenu(decltype(_entities) &entities);

    MainMenu(const MainMenu &) = delete;
    MainMenu &operator=(const MainMenu &) = delete;

    void tick(double deltaTime) final;
};
