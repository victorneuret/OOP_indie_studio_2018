/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombTicking.hpp
*/

#pragma once

#include "ECS/Abstracts/ASystem.hpp"

namespace Game::System {
    class BombTicker;
}

class Game::System::BombTicker : public Engine::ECS::ASystem {
public:
    BombTicker();

    BombTicker(const BombTicker &) = delete;
    BombTicker &operator=(const BombTicker &) = delete;

    void update(double dt) override;
};