/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ApplyPowerUp.cpp
*/

#include <iostream>

#include "ECS/Systems/ApplyPowerUp.hpp"

void ECS::Systems::ApplyPowerUp::applySpdUp() const
{
    std::cout << "Increase the speed of a player" << std::endl;
}

void ECS::Systems::ApplyPowerUp::applyBombUp() const
{
    std::cout << "Increase the number of the bomb by 1" << std::endl;
}

void ECS::Systems::ApplyPowerUp::applyFireUp() const
{
    std::cout << "Increase the max blast radius by 1" << std::endl;
}

void ECS::Systems::ApplyPowerUp::applyWallPass() const
{
    std::cout << "Allow the player to pass through soft blocks" << std::endl;
}