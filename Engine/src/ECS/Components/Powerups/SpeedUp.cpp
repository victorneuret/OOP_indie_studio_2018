/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include <iostream>

#include "ECS/Components/Powerups/SpeedUp.hpp"

Engine::Component::PowerUps::SpeedUp::SpeedUp()
    : APowerUp("SpeedUp", 5)
{
}