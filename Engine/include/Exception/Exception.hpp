#include <utility>

/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Exception.hpp
*/

#pragma once

#include <string>

#include "AException.hpp"

enum ExceptionType {
    General_Engine,
    General_Memory,
    General_Permission,
    General_Math,
    General_Not_Implemented,
    General_Serialization
};

template<ExceptionType Type>
class Exception : public AException {
public:
    explicit Exception(const std::string &what = "Exception")
        : AException(what)
    {}

    const char *what() const noexcept override
    {
        return _what.c_str();
    }
};
