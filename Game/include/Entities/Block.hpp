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

namespace Game::Entity {
    class Block;
}

class Game::Entity::Block final : public Engine::ECS::AEntity<Block> {
public:
    explicit Block(const Engine::ECS::System::Renderer &renderer, const std::string &model = std::string("res/models/weapon.md2"), const std::string &texture = std::string("res/models/weapon.pcx"));
    Block(const Block &) = delete;
    Block &operator=(const Block &) = delete;

    ~Block() final = default;
};
