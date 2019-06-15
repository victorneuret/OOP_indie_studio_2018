/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Selection.hpp
*/

#pragma once

#include "Abstracts/AScene.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Effects/AudioVisualizer.hpp"

namespace Game::Scene {
    class Selection;
}

class Game::Scene::Selection final : public Engine::Abstracts::AScene {
public:
    Selection();
    ~Selection() override = default;

    Selection(const Selection &) = delete;
    Selection &operator=(const Selection &) = delete;

    void tick(double deltaTime) override;
    void sceneShowing() override;
    void sceneHiding(const AScene *newParent) override;
};
