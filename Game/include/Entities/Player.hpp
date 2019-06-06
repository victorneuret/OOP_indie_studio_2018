/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Player.hpp
*/

#pragma once

#include <string>
#include <memory>
#include <irrlicht/irrlicht.h>

#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Components/Model3D.hpp"
#include "Math/Vector/Vec3.hpp"

namespace Game::Entity {
    class Player;
}

class Game::Entity::Player final : public Engine::ECS::AEntity<Player> {
protected:
    Engine::Math::Vec3d _pos{0, 0, 0};

public:
    explicit Player(const Engine::ECS::System::Renderer &renderer, const Engine::Math::Vec3f &pos = {0, 0, 0}, const std::string &model = std::string("assets/models/tris.md2"), const std::string &texture = std::string("res/models/blade_blue2.pcx"));
    Player(const Player &) = delete;
    Player &operator=(const Player &) = delete;

    ~Player() override = default;
};