/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Colors.hpp
*/

#pragma once

#include <cstdint>

namespace Engine::Utils {
    struct Color;
}

struct Engine::Utils::Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color(const decltype(r) &_r, const decltype(g) &_g, const decltype(b) &_b, const decltype(a) &_a = 255);
    Color(const Color &rhs) = default;
    Color &operator=(const Color &rhs) noexcept = default;
};
