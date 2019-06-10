/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.hpp
*/

#pragma once

#include "Math/Vector/Vec3.hpp"
#include "ECS/Abstracts/AEntity.hpp"

namespace Game::Entity {
    class Character;
}

class Game::Entity::Character : public Engine::ECS::AEntity {
public:
    explicit Character();
    Character(const Character &) = delete;
    Character &operator=(const Character &) = delete;

    ~Character() override = default;
};
