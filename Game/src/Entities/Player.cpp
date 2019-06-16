/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.cpp
*/

#include <memory>

#include "Entities/Player.hpp"
#include "Math/Vector/Vec3.hpp"

Game::Entity::Player::Player(const Engine::Math::Vec3f &pos, const std::string &texture, const std::string &model)
    : Character{pos, texture, model}
{}