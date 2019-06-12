/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AEntity.cpp
*/

#include "ECS/Abstracts/AEntity.hpp"

namespace Engine::ECS {
    size_t getNextEntityID() noexcept
    {
        static size_t ID = 0;
        return ID++;
    }
}
