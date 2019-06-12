/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AEntity.hpp
*/

#pragma once

#include <cstddef>
#include <vector>
#include <algorithm>
#include <memory>

#include "Utils/Logger.hpp"
#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Components/Renderer.hpp"
#include "ECS/Abstracts/AComponent.hpp"
#include "ECS/Interfaces/IComponent.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/Engine/ECS/ECSException.hpp"

namespace Engine::ECS {
    class AEntity;

    size_t getNextEntityID() noexcept;
}

class Engine::ECS::AEntity : public IEntity {
protected:
    size_t _id;
    Type _type{};
    std::vector<std::shared_ptr<IComponent>> _components{};

public:
    explicit AEntity(decltype(_type) type);
    ~AEntity() override = default;

    decltype(_id) getID() const noexcept final;

    void show() noexcept final;
    void hide() noexcept final;
    void addComponent(std::shared_ptr<IComponent> &component);
    void removeComponent(const std::string &id);

    decltype(_type) getType() const noexcept final;
    const std::vector<std::shared_ptr<IComponent>> &getComponents() const noexcept final;
    std::shared_ptr<IComponent> &getComponentByID(const std::string &id) override;
};
