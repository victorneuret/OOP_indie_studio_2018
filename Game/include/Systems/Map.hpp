/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapSystem.hpp
*/

#pragma once

#include <vector>
#include <string>
#include <memory>

#include "ECS/Interfaces/IEntity.hpp"
#include "ECS/Abstracts/ASystem.hpp"

constexpr int MAP_WIDTH = 11;
constexpr int MAP_HEIGHT = 11;

namespace Game::System {
    class Map;
}

class Game::System::Map : public Engine::ECS::ASystem<Map> {
private:
    std::vector<std::string> _map{};

    void _createFirstSquare() noexcept;
    void _duplicateWidth() noexcept;
    void _duplicateHeight() noexcept;
    void _createMap(std::vector<std::shared_ptr<Engine::ECS::IEntity>> &entities) noexcept;

public:
    void update(double dt, std::vector<std::shared_ptr<Engine::ECS::IEntity>> &entities) final;
};

