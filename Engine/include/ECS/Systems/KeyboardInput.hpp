/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Input
*/

#pragma once

#include "ECS/Abstracts/Systems/AInput.hpp"

namespace Engine::ECS::Systems {
    class KeyboardInput;
}

class Engine::ECS::Systems::KeyboardInput : public Engine::ECS::Systems::AInput {
public:
	bool OnEvent(irr::SEvent &event) final;
};
