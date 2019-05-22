/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AException.cpp
*/

#include "Exception/AException.hpp"

AException::AException(const std::string &what)
    : _what{std::string{"Exception: " + what}}
{
}

const char *AException::what() const noexcept
{
    return _what.c_str();
}
