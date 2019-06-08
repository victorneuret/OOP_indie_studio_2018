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

    const char *what() const noexcept override = 0;
    virtual std::string what_stdstr() const noexcept final;
protected:
    const std::string _what;
};
