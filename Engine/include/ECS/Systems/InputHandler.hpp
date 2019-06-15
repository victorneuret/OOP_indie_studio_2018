/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** InputHandler.hpp
*/

#pragma once

#include <map>

#include "ECS/Abstracts/ASystem.hpp"
#include "ECS/Abstracts/AEntity.hpp"
#include "ECS/Interfaces/InputType.hpp"

namespace Engine::ECS::System {
    class InputHandler;
}

class Engine::ECS::System::InputHandler : public ASystem {
protected:
    std::map<size_t, std::shared_ptr<InputType>> _inputs{};

public:
    InputHandler();
    ~InputHandler() override = default;

    void bind(size_t id, const std::shared_ptr<InputType> &input);

    void update(double dt) override;
};
