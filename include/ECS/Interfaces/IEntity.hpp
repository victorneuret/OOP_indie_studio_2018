/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** IEntity.hpp
*/

namespace Engine {
    namespace ECS {
        class IEntity;
    }
}

class Engine::ECS::IEntity {
public:
    virtual ~IEntity() = default;
};
