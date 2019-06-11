/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Image.cpp
*/


#include "ECS/Entities/Image.hpp"
#include "ECS/Components/Image.hpp"
#include "Math/Vector/Vec2.hpp"

Engine::Entity::Image::Image(const std::string &texturePath, const Math::Vec2u &position)
        : AEntity(AEntity::Type::MODEL2D)
{
    std::shared_ptr<Engine::ECS::IComponent> image = std::make_shared<Engine::ECS::Component::Image>(texturePath, position);
    addComponent(image);

    std::shared_ptr<Engine::ECS::IComponent> _renderer = std::make_shared<Engine::ECS::Component::Renderer>();
    addComponent(_renderer);
}