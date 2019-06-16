/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EndGame.hpp
*/

#pragma once

#include "Abstracts/AScene.hpp"

namespace Game::Scene {
    class EndGame;
}

class Game::Scene::EndGame final : public Engine::Abstracts::AScene {
public:
    EndGame(bool draw);

    EndGame(const EndGame &) = delete;
    EndGame &operator=(const EndGame &) = delete;

    void tick(double deltaTime) override;
    void sceneShowing() override;
    void sceneHiding(const AScene *newParent) override;
};
