/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** EngineException.hpp
*/

#pragma once

#include "Exception/Exception.hpp"

enum EngineExceptionType {
    Engine_ECS,
    Engine_Renderer,
    Engine_Updater,
    Engine_Sound
};

template<EngineExceptionType Type>
class EngineException : public Exception<General_Engine> {
public:
    explicit EngineException(const std::string &what = "EngineException")
        : Exception{what}
    {
    }
};
