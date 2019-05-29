/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** IEntity.hpp
*/

#pragma once

namespace Engine::ECS {
    class IEntity;
}

class Engine::ECS::IEntity {
public:
    virtual ~IEntity() = default;
    virtual size_t getID() const noexcept = 0;
};
