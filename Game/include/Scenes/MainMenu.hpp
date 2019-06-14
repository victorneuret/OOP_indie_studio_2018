/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.hpp
*/

#pragma once

#include "Abstracts/AScene.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Effects/AudioVisualizer.hpp"

namespace Game::Scene {
    class MainMenu;
}

class Game::Scene::MainMenu final : public Engine::Abstracts::AScene {
private:
    decltype(std::declval<Engine::ECS::System::Audio>().getSound("").second) _music;
    std::unique_ptr<AudioVisualizer> _audioVisualizer{nullptr};
public:
    MainMenu();
    ~MainMenu() override;

    MainMenu(const MainMenu &) = delete;
    MainMenu &operator=(const MainMenu &) = delete;

    void tick(double deltaTime) override;
    void sceneShowing() override;
    void sceneHiding(const AScene *newParent) override;
};
