/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ASystem.cpp
*/

#include <utility>

#include "ECS/Abstracts/ASystem.hpp"

Engine::ECS::ASystem::ASystem(const decltype(_id) &id)
    : _id{std::string(id)}
{
}

const decltype(Engine::ECS::ASystem::_id) &Engine::ECS::ASystem::getID() const noexcept
{
    return _id;
}
