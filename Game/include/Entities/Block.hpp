/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Box.hpp
*/

#pragma once

#include <string>

#include "ECS/Systems/Renderer.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "Math/Vector/Vec3.hpp"

namespace Game::Entity {
    class Block;
}

class Game::Entity::Block : public Engine::ECS::AEntity<Block> {
public:
    explicit Block(const Engine::ECS::System::Renderer &renderer, const Engine::Math::Vec3f &pos = {0, 0, 0}, const std::string &model = std::string("assets/models/weapon.md2"));
    Block(const Block &) = delete;
    Block &operator=(const Block &) = delete;

    ~Block() override = default;
};
