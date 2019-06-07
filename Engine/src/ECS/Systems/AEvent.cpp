/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AEvent.cpp
*/

#include "ECS/Abstracts/Systems/AEvent.hpp"

Engine::ECS::System::AEvent::AEvent(const std::string &id)
    : ASystem{id}
{}

bool Engine::ECS::System::AEvent::OnEvent(const irr::SEvent &event)
{
    return false;
}