/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Manager.hpp
*/

#pragma once

#include <vector>
#include <memory>

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Interfaces/ISystem.hpp"
#include "ECS/Systems/Renderer.hpp"
#include "Abstracts/AScene.hpp"

namespace Engine::ECS {
    class Manager;
}

class Engine::ECS::Manager {
private:
    Manager() = default;

    static std::vector<std::shared_ptr<ISystem>> _systems;
    static std::vector<std::shared_ptr<Abstracts::AScene>> _scenes;

    static std::unique_ptr<Manager> _instance;

public:
    static Manager &getInstance();

    Manager(const Manager &) = delete;
    Manager &operator=(const Manager &) = delete;

    decltype(_systems) &getSystems() noexcept;
    std::shared_ptr<ISystem> &getSystemByID(const std::string &id);
    void addSystem(std::shared_ptr<ISystem> &system);

    decltype(_scenes) &getScenes() noexcept;
    std::shared_ptr<Abstracts::AScene> &getSceneByID(const std::string &id);
    void addScene(std::shared_ptr<Abstracts::AScene> &scene);
    void sceneManager(double dt, std::shared_ptr<System::Renderer> &renderer);
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> getUpdatedEntities();
    std::vector<std::shared_ptr<Engine::Abstracts::AScene>> getUpdatedScenes();
};
