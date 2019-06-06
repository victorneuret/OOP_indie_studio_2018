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

namespace Engine::ECS {
    class Manager;
}

class Engine::ECS::Manager {
private:
    Manager() = default;

    static std::vector<std::shared_ptr<IEntity>> _entities;
    static std::vector<std::shared_ptr<ISystem>> _systems;

    static std::unique_ptr<Manager> _instance;

public:
    static Manager &getInstance();

    Manager(const Manager &) = delete;
    Manager &operator=(const Manager &) = delete;

    std::shared_ptr<IEntity> &getEntityByID(size_t id);
    decltype(_entities) &getEntities() noexcept;
    void addEntity(std::shared_ptr<IEntity> &entity);

    decltype(_systems) &getSystems() noexcept;
    std::shared_ptr<ISystem> &getSystemsByID(const std::string &id);
    void addSystem(std::shared_ptr<ISystem> &system);
};
