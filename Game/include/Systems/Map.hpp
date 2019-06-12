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
#include "Math/Vector/Vec3.hpp"

#define INDEX_TO_POS(index) ((index) * 10)

constexpr uint8_t MAP_WIDTH = 15;
constexpr uint8_t MAP_HEIGHT = 15;

namespace Game::System {
    class Map;
}

class Game::System::Map : public Engine::ECS::ASystem {
private:
    std::vector<std::string> _map{};
    std::vector<std::string> _actualMap{};

    std::vector<std::vector<std::shared_ptr<Engine::ECS::IEntity>>> _blocks{};

    void _createFirstSquare() noexcept;
    void _duplicateWidth() noexcept;
    void _duplicateHeight() noexcept;
    void _createMap() noexcept;
    std::shared_ptr<Engine::ECS::IEntity> _createBlock(Engine::Math::Vec3f vec, const std::string &texture, bool breakable) noexcept;
    void _placeCameraAndLight() noexcept;

public:
    Map();
    void update(double dt) final;

    decltype(_actualMap) getActualMap() const noexcept;
    void setActualMap(decltype(_actualMap) &map) noexcept;
    void removeBlock(const Engine::Math::Vec2i &pos);

};

