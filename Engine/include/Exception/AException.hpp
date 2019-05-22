/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Exception.hpp
*/

#pragma once

#include <string>
#include <exception>

class AException : public std::exception {
public:
    explicit AException(const std::string &what);

    const char *what() const noexcept override;
protected:
    const std::string _what;
};
