/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ECSException.hpp
*/

#pragma once

#include "Exception/Engine/EngineException.hpp"

enum ECSExceptionType {
    ECS_Entity,
    ECS_Component,
    ECS_System,
    ECS_Renderer
};

template<ECSExceptionType Type>
class ECSException : public EngineException<Engine_ECS> {
public:
    explicit ECSException(const std::string &what = "ECSException")
        : EngineException(what)
    {}
};
