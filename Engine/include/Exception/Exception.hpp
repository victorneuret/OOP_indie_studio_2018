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
    General_Not_Implemented
};

template<ExceptionType Type>
class Exception : public AException {
public:
    explicit Exception(const std::string &what = "Exception")
        : AException(what)
    {}
};
