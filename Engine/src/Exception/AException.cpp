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

std::string AException::what_stdstr() const noexcept
{
    return std::string(what());
}
