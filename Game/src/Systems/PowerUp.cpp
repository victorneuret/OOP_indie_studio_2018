/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** PowerUp.cpp
*/

#include "Systems/PowerUp.hpp"

Game::System::PowerUp::PowerUp()
    : ASystem("PowerUp")
{}

void Game::System::PowerUp::bombUp(Game::Entity::Character &player) const
{
    player.addBomb();
}

void Game::System::PowerUp::speedUp(Game::Entity::Character &player) const
{
    player.setSpeed(player.getSpeed() * 1.5);
}

void Game::System::PowerUp::fireUp(Game::Entity::Character &player) const
{
    player.rangeIncrease();
}

void Game::System::PowerUp::wallPass(Game::Entity::Character &player) const
{
    // Need collisions
}

void Game::System::PowerUp::update(double dt)
{}