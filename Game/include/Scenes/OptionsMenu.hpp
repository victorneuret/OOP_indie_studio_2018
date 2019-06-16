//
// Created by fury on 6/16/19.
//

#pragma once

#include "Abstracts/AScene.hpp"

namespace Game::Scene {
    class OptionsMenu;
}

class Game::Scene::OptionsMenu final : public Engine::Abstracts::AScene {
public:
    OptionsMenu();

    OptionsMenu(const OptionsMenu &) = delete;
    OptionsMenu &operator=(const OptionsMenu &) = delete;

    void tick(double deltaTime) override;
    void sceneShowing() override;
    void sceneHiding(const AScene *newParent) override;
};