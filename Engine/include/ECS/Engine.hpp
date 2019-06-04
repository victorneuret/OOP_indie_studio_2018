/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Engine.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <map>

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Interfaces/ISystem.hpp"
#include "AScene.hpp"

namespace Engine::ECS {
    class Engine;
}

class Engine::ECS::Engine {
private:
    std::vector<std::shared_ptr<ISystem>> _systems{};
    std::map<AScene::SceneType , AScene> _scenes{};

public:
    decltype(_systems) &getSystems() noexcept;
    const decltype(_systems) &getSystems() const noexcept;
    void addSystem(std::shared_ptr<ISystem> &system);
};
