/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AComponent.cpp
*/

#include "ECS/Abstracts/AComponent.hpp"

Engine::ECS::AComponent::AComponent(const decltype(_id) &id)
    : _id{std::string{id}}
{
}

const decltype(Engine::ECS::AComponent::_id) &Engine::ECS::AComponent::getID() const noexcept
{
    return _id;
}
