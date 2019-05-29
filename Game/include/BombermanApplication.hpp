/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombermanApplication.hpp
*/

#pragma once

#include "GameApplication.hpp"

class BombermanApplication final : public Engine::GameApplication {
public:
    BombermanApplication();

    BombermanApplication(const BombermanApplication &) = delete;
    BombermanApplication &operator=(const BombermanApplication &) = delete;

    void onAppStartup() override;
    void tick(double deltaTime) override;
    void onAppShutdown() override;
    void onAppCrash() override;
};
