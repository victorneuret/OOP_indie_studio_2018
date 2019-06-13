/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** APower-up.cpp
*/

#include "ECS/Components/Powerups/APowerUp.hpp"

Engine::ECS::Components::APowerUp::APowerUp(const std::string &name, const double &duration)
    : AComponent(name), _duration(duration)
{
}

//Engine::ECS::Component::Timer Engine::ECS::Components::APowerUp::getCooldown() const
//{
//    return _cooldown;
//}

double Engine::ECS::Components::APowerUp::getDuration() const
{
    return _duration;
}