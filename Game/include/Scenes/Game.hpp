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
    class Game;
}

class Game::Scene::Game final : public Engine::Abstracts::AScene {
private:
    decltype(std::declval<Engine::ECS::System::Audio>().getSound("").second) _music{};
    std::unique_ptr<AudioVisualizer> _audioVisualizer{nullptr};
public:
    Game();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    void tick(double deltaTime) override;
    void sceneShowing() override;
    void sceneHiding(const AScene *newParent) override;
};