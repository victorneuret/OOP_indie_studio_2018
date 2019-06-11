/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** RectTests.cpp
*/

#include <criterion/criterion.h>

#include "Math/Rect.hpp"

using namespace Engine::Math;

Test(Rect, Constructors)
{
    Rect_i rect;

    cr_assert(rect.x == 0);
    cr_assert(rect.y == 0);
    cr_assert(rect.w == 0);
    cr_assert(rect.h == 0);

    rect = Rect_i{3, 4, 5, 6};

    cr_assert(rect.x == 3);
    cr_assert(rect.y == 4);
    cr_assert(rect.w == 5);
    cr_assert(rect.h == 6);
}

Test(Rect, Equality)
{
    Rect_i rect{55, 22, 13, 8};

    cr_assert(rect == Rect<int>(55, 22, 13, 8));
    cr_assert(rect != Rect_i{});
}