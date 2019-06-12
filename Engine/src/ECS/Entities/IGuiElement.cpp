/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** IGuiElement.cpp
*/

#include "ECS/Interfaces/Entities/IGuiElement.hpp"

decltype(Engine::ECS::Entity::IGuiElement::GLOBAL_ID) Engine::ECS::Entity::IGuiElement::GLOBAL_ID{-1};

const decltype(Engine::ECS::Entity::IGuiElement::_guiID) &Engine::ECS::Entity::IGuiElement::getGuiID() const
{
    return _guiID;
}