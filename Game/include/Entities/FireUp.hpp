/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** FireUp.hpp
*/

#pragma once

#include "ECS/Abstracts/AEntity.hpp"
#include "Entities/Character.hpp"

namespace Game::Entity {
    class FireUp;
}

class Game::Entity::FireUp : public Engine::ECS::AEntity {
public:
    FireUp(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/block/powerup.obj"));

    FireUp(const FireUp &) = delete;
    FireUp &operator=(const FireUp &) = delete;

    ~FireUp() override = default;

    void applyEffect(Game::Entity::Character player);
};
