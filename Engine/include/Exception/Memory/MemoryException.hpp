/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** MemoryException.hpp
*/

#pragma once

#include "Exception/Exception.hpp"

enum MemoryExceptionType {
    Memory_Allocation_Failed
};

template<MemoryExceptionType Type>
class MemoryException : public Exception<General_Memory> {
public:
    explicit MemoryException(const std::string &what = "MemoryException")
        : Exception{what}
    {
    }
};