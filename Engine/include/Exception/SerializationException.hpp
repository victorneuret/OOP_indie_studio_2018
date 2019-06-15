/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SerializationException.hpp
*/

#pragma once

#include "Exception/Exception.hpp"

class SerializationException : public Exception<General_Serialization> {
public:
    explicit SerializationException(const std::string &what = "SerializationException")
        : Exception(what)
    {}
};
