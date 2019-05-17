/*
** EPITECH PROJECT, 2018
** bomberman	
** File description:
** AComponent.cpp
*/

#include "ECS/Abstracts/AComponent.hpp"

decltype(Engine::ECS::AComponent::ID) Engine::ECS::AComponent::ID = 0;

decltype(Engine::ECS::AComponent::_id) Engine::ECS::AComponent::id() const noexcept
{
    return _id;
}