/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MainMenu.hpp
*/

#pragma once

#include "Abstracts/AScene.hpp"
#include "ECS/Systems/Audio.hpp"

namespace Game::Scene {
    class MainMenu;
}

class Game::Scene::MainMenu final : public Engine::Abstracts::AScene {
private:
    decltype(std::declval<Engine::ECS::System::Audio>().getSound("").second) _music;
public:
    MainMenu();
    ~MainMenu();

    MainMenu(const MainMenu &) = delete;
    MainMenu &operator=(const MainMenu &) = delete;

    void tick(double deltaTime) override;
};
