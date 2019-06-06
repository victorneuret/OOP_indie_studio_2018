/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Engine.hpp
*/

#pragma once

#include <vector>
#include <memory>

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Interfaces/ISystem.hpp"
#include "Scenes/AScene.hpp"

namespace Engine::ECS {
    class Engine;
}

class Engine::ECS::Engine {
private:
    Engine() = default;

    static std::vector<std::shared_ptr<ISystem>> _systems;
    static std::vector<std::shared_ptr<Scene::AScene>> _scenes;
    static std::unique_ptr<Engine> _instance;

public:
    static Engine &getInstance();

    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;

    decltype(_systems) &getSystems() noexcept;
    std::shared_ptr<ISystem> &getSystemByID(const std::string &id);
    void addSystem(std::shared_ptr<ISystem> &system);

    decltype(_scenes) &getScenes() noexcept;
    std::shared_ptr<Scene::AScene> &getSceneByID(const std::string &id);
    void addScene(std::shared_ptr<Scene::AScene> &scene);
    void sceneManager(double deltaTime);

};
