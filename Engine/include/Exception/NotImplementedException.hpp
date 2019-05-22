/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** NotImplementedException.hpp
*/

#pragma once

#include "Exception/Exception.hpp"

class NotImplementedException : public Exception<General_Not_Implemented> {
public:
    explicit NotImplementedException(const std::string &what = "NotImplementedException")
        : Exception(what)
    {}
};
