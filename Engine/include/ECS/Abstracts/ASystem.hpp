/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ASystem.hpp
*/

#pragma once

#include <vector>

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Interfaces/ISystem.hpp"

namespace Engine::ECS {
    template<typename T>
    class ASystem;
}

template<typename T>
class Engine::ECS::ASystem : public ISystem {
private:
    std::string _id{};

public:
    explicit ASystem(const decltype(_id) &id)
        : _id(std::string{id})
    {}
    ~ASystem() override = default;

    const decltype(_id) &getID() const noexcept final
    {
        return _id;
    }

    void update(double dt, std::vector<std::shared_ptr<IEntity>> &entities) override = 0;

};

