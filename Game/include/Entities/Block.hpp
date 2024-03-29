/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Box.hpp
*/

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ECS/Abstracts/AEntity.hpp"
#include "Exception/AException.hpp"
#include "Math/Vector/Vec3.hpp"

namespace Game::Entity {
    class Block;
}

class Game::Entity::Block : public Engine::ECS::AEntity {
private:
    bool _breakable;

public:
    explicit Block(bool breakable, const Engine::Math::Vec3f &pos = {0, 0, 0}, const std::string &model = std::string("assets/models/block/Column.obj"));
    Block(const Block &) = delete;
    Block &operator=(const Block &) = delete;

    decltype(_breakable) isBreakable() const noexcept;

    ~Block() override = default;
};
