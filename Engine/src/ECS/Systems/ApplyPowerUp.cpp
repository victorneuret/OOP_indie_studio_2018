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