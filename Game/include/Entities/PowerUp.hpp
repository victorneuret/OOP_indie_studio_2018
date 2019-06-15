/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PowerUp.hpp
*/

#pragma once

#include "ECS/Abstracts/AEntity.hpp"

namespace Game::Entity {
    class PowerUp;
}

class Game::Entity::PowerUp : public Engine::ECS::AEntity {
public:
    PowerUp(const Engine::Math::Vec3f &pos, const std::string &model = std::string("assets/models/cube.obj"));

    PowerUp(const PowerUp &) = delete;
    PowerUp &operator=(const PowerUp &) = delete;

    ~PowerUp() override = default;
};
