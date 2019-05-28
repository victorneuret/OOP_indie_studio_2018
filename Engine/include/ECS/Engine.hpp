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

namespace Engine::ECS {
    class Engine;
}

class Engine::ECS::Engine {
private:
    std::vector<std::shared_ptr<IEntity>> _entities{};
    std::vector<std::shared_ptr<ISystem>> _systems{};

public:
    std::shared_ptr<IEntity> &getEntityByID(size_t id);
    decltype(_entities) &getEntities() noexcept;
    const decltype(_entities) &getEntities() const noexcept;
    void addEntity(std::shared_ptr<IEntity> &entity);

    decltype(_systems) &getSystems() noexcept;
    const decltype(_systems) &getSystems() const noexcept;
    void addSystem(std::shared_ptr<ISystem> &system);
};
