/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SoundException.hpp
*/

#pragma once

#include "Exception/Engine/ECS/ECSException.hpp"

enum SoundExceptionType {
    Sound_File_Not_Found
};

template<SoundExceptionType Type>
class SoundException : public ECSException<ECS_System> {
public:
    explicit SoundException(const std::string &what = "SoundException")
        : ECSException(what)
    {}
};
