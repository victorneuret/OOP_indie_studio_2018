/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ApplyPowerUp.hpp
*/

#pragma once

#include "ECS/Abstracts/ASystem.hpp"

namespace ECS::Systems {
    class ApplyPowerUp;
}

class ECS::Systems::ApplyPowerUp : public Engine::ECS::ASystem<ECS::Systems::ApplyPowerUp> {
public:
    void applySpdUp() const;
private:
};