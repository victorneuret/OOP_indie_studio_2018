/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Permission.hpp
*/

#pragma once

#include "Exception/Exception.hpp"

enum PermissionExceptionType {
    Permission_Denied
};

template<PermissionExceptionType Type>
class PermissionException : public Exception<General_Permission> {
public:
    explicit PermissionException(const std::string &what = "PermissionException")
        : Exception{what}
    {
    }
};