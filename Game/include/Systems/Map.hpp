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
#include "ECS/Systems/Renderer.hpp"

constexpr uint8_t MAP_WIDTH = 11;
constexpr uint8_t MAP_HEIGHT = 11;

namespace Game::System {
    class Map;
}

class Game::System::Map : public Engine::ECS::ASystem<Map> {
private:
    std::vector<std::string> _map{};

    void _createFirstSquare() noexcept;
    void _duplicateWidth() noexcept;
    void _duplicateHeight() noexcept;
    void _createMap() noexcept;

public:
    Map();
    void update(double dt) final;
};

