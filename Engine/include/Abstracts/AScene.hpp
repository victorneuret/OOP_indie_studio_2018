/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** AScene
*/

#pragma once

#include <vector>
#include <memory>
#include <string>

#include "ECS/Interfaces/IEntity.hpp"

namespace Engine::Abstracts {
    class AScene;
}

class Engine::Abstracts::AScene {
protected:
    std::string _id{};
    std::vector<std::shared_ptr<Engine::ECS::IEntity>> _entities{};
    bool _opaque{true};
    bool _updateChild{false};

public:
    AScene(decltype(_id) id, decltype(_entities) entities, bool opaque, bool updateChild);
    virtual ~AScene() = default;

    AScene(const AScene &) = delete;
    AScene &operator=(const AScene &) = delete;
    virtual void addEntity(std::shared_ptr<Engine::ECS::IEntity> &entity) final;
    virtual void removeEntity(const std::shared_ptr<Engine::ECS::IEntity> &entity) final;
    virtual void removeEntityByID(size_t id) final;

    virtual std::shared_ptr<Engine::ECS::IEntity> &getEntityByID(size_t id) final;
    virtual decltype(_entities) &getEntities() noexcept final;
    virtual const decltype(_entities) &getEntities() const noexcept final;
    virtual const decltype(_id) &getID() const noexcept final;

    virtual decltype(_opaque) isOpaque() const noexcept final;
    virtual decltype(_updateChild) isUpdateChild() const noexcept final;

    virtual void updateChild(bool updateChild) noexcept final;

    virtual void tick(double deltaTime) = 0;
    virtual void sceneShowing() = 0;
    virtual void sceneHiding(const AScene *newParent) = 0;
};
