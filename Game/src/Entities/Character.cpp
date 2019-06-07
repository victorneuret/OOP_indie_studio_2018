/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Character.cpp
*/

#include <Entities/Character.hpp>

#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"

Game::Entity::Character::Character()
    : AEntity(AEntity::Type::MODEL3D)
{}
