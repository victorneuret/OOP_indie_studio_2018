/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** AEntity.hpp
*/

#include <cstddef>
#include <vector>

#include "ECS/Interfaces/IEntity.hpp"

namespace Engine::ECS {
    class AEntity;
}

class Engine::ECS::AEntity : public Engine::ECS::IEntity {
protected:
    std::vector<size_t> _components{};

public:
    ~AEntity() override = default;
    void addComponent(size_t id);
    void removeComponent(size_t id);
    const decltype(_components) &components() const noexcept;
};
