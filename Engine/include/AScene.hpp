/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Scene
*/

#pragma once

#include <vector>
#include <memory>

#include "ECS/Interfaces/IEntity.hpp"

namespace Engine {
    class AScene;
}

class Engine::AScene final {
public:
    enum class SceneType {
        GAME,
        PAUSE,
        MENU,
        SETTINGS
    };

protected:
    SceneType _type{};
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> _entities{};
    bool _opaque{true};
    bool _updateChild{false};

public:
    AScene(SceneType type, decltype(_entities) &entities, bool opaque, bool updateChild);

    virtual void addEntity(std::shared_ptr<Engine::ECS::IEntity> &entity);
    virtual void removeEntity(const std::shared_ptr<Engine::ECS::IEntity> &entity);
    virtual std::shared_ptr<Engine::ECS::IEntity> &getEntityByID(size_t id);
    virtual decltype(_entities) &getEntities() noexcept;
    virtual const decltype(_entities) &getEntities() const noexcept;
    virtual void updateChild(bool updateChild);
    virtual decltype(_type) getType() const noexcept;
};
