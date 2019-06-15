/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PowerUp.hpp
*/

#pragma once

#include "ECS/Abstracts/AEntity.hpp"

namespace Game::Entity {
    class BombUp;
}

class Game::Entity::BombUp : public Engine::ECS::AEntity {
public:
    BombUp(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/block/powerup.obj"));

    BombUp(const BombUp &) = delete;
    BombUp &operator=(const BombUp &) = delete;

    ~BombUp() override = default;
};
