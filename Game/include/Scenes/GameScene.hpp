/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Game.hpp.cpp
*/

#pragma once

#include "Abstracts/AScene.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Effects/AudioVisualizer.hpp"

namespace Game::Scene {
    class GameScene;
}

class Game::Scene::GameScene final : public Engine::Abstracts::AScene {
private:
    decltype(std::declval<Engine::ECS::System::Audio>().getSound("").second) _music{};
    std::unique_ptr<AudioVisualizer> _audioVisualizer{nullptr};
    bool _complete{false};

    static void _checkInputs();

    void _backgroundAnimations();
    void _checkEndGame();
public:
    GameScene();

    GameScene(const GameScene &) = delete;
    GameScene &operator=(const GameScene &) = delete;

    void tick(double deltaTime) override;
    void sceneShowing() override;
    void sceneHiding(const AScene *newParent) override;
};
