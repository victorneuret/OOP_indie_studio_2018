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
    Engine() = default;

    static std::vector<std::shared_ptr<IEntity>> _entities;
    static std::vector<std::shared_ptr<ISystem>> _systems;
    static std::map<AScene::SceneType , AScene*> _scenes;

    static std::unique_ptr<Engine> _instance;

public:
    static Engine &getInstance();

    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;

    decltype(_systems) &getSystems() noexcept;
    std::shared_ptr<ISystem> &getSystemsByID(const std::string &id);
    void addSystem(std::shared_ptr<ISystem> &system);

    AScene &getScene(const AScene::SceneType type);
    void addScene(AScene &scene);

};
