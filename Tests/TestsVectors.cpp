/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Test.cpp
*/

#include <criterion/criterion.h>

#include "Math/Vector/Vec2.hpp"
#include "Math/Vector/Vec3.hpp"

using namespace Engine::Math;

Test(Vector2, Constructors)
{
    Vec2d v1;
    Vec2d v2{5, -6};
    Vec2d v3{-42, 16};

    cr_assert_eq(v1.x, 0);
    cr_assert_eq(v1.y, 0);

    cr_assert_eq(v2.x, 5);
    cr_assert_eq(v2.y, -6);

    cr_assert_eq(v3.x, -42);
    cr_assert_eq(v3.y, 16);
}

Test(Vector3, Constructors)
{
    Vec3d v1;
    Vec3d v2{5, -6, 12};
    Vec3d v3{-42, 16, 5};

    cr_assert_eq(v1.x, 0);
    cr_assert_eq(v1.y, 0);
    cr_assert_eq(v1.z, 0);

    cr_assert_eq(v2.x, 5);
    cr_assert_eq(v2.y, -6);
    cr_assert_eq(v2.z, 12);

    cr_assert_eq(v3.x, -42);
    cr_assert_eq(v3.y, 16);
    cr_assert_eq(v3.z, 5);
}

Test(Vector2, Equality)
{
    Vec2u vec{5, 5};

    cr_assert_eq(Vec2f(5.2, 6.3), Vec2f(5.2, 6.3));
    cr_assert_eq(Vec2l(50, 50), Vec2l(50, 50));
    cr_assert_eq(vec, decltype(vec)(vec));

    cr_assert_neq(Vec2f(5.2, 6.3), Vec2f(0, 6.3));
    cr_assert_neq(Vec2l(50, 50), Vec2l(42, 50));
    cr_assert_neq(decltype(vec)(), decltype(vec)(vec));
}

Test(Vector3, Equality)
{
    Vec3u vec{5, 5, 5};

    cr_assert_eq(Vec3f(5.2, 6.3, 0.1), Vec3f(5.2, 6.3, 0.1));
    cr_assert_eq(Vec3l(50, 50, -50), Vec3l(50, 50, -50));
    cr_assert_eq(vec, decltype(vec)(vec));

    cr_assert_neq(Vec3f(5.2, 6.3, 19.413), Vec3f(0, 6.3, 19.413));
    cr_assert_neq(Vec3l(50, 50, 0), Vec3l(42, 50, 0));
    cr_assert_neq(decltype(vec)(), decltype(vec)(vec));
}

Test(Vector2, OperationAdd)
{
    cr_assert(Vec2i(21, 11) + 2 == Vec2i(23, 13));
    cr_assert(Vec2u(6, 7) + 7 == Vec2u(13, 14));
    cr_assert(Vec2i(44, 12) + 0 == Vec2i(44, 12));
    cr_assert(Vec2d(423.4234, 123.323) + 0 == Vec2d(423.4234, 123.323));

    cr_assert(Vec2i(21, 11) + Vec2i(2, 4) == Vec2i(23, 15));
    cr_assert(Vec2u(6, 7) + Vec2u(7, 6) == Vec2u(13, 13));
    cr_assert(Vec2i(44, 12) + Vec2i(0, 2) == Vec2i(44, 14));
    cr_assert(Vec2d(423.4234, 123.323) + Vec2d(0.0, 0.0) == Vec2d(423.4234, 123.323));
}

Test(Vector3, OperationAdd)
{
    cr_assert(Vec3i(21, 11, 15) + 2 == Vec3i(23, 13, 17));
    cr_assert(Vec3u(6, 7, 10) + 7 == Vec3u(13, 14, 17));
    cr_assert(Vec3i(44, 12, 1) + 0 == Vec3i(44, 12, 1));
    cr_assert(Vec3d(423.4234, 123.323, 8888) + 0 == Vec3d(423.4234, 123.323, 8888));

    cr_assert(Vec3i(21, 11, 1) + Vec3i(2, 4, 42) == Vec3i(23, 15, 43));
    cr_assert(Vec3u(6, 7, 5) + Vec3u(7, 6, 5) == Vec3u(13, 13, 10));
    cr_assert(Vec3i(44, 12, 1) + Vec3i(0, 2, 12) == Vec3i(44, 14, 13));
    cr_assert(Vec3d(423.4234, 123.323, 943948.12323234) + Vec3d(0.0, 0.0, 1) == Vec3d(423.4234, 123.323, 943949.12323234));
}

Test(Vector2, OperationMul)
{
    cr_assert(Vec2i(21, 11) * 2 == Vec2i(42, 22));
    cr_assert(Vec2u(6, 7) * 7 == Vec2u(42, 49));
    cr_assert(Vec2i(44, 12) * 0 == Vec2i(0, 0));
    cr_assert(Vec2d(423.4234, 123.323) * 0 == Vec2d(0.0, 0.0));

    cr_assert(Vec2i(21, 11) * Vec2i(2, 4) == Vec2i(42, 44));
    cr_assert(Vec2u(6, 7) * Vec2u(7, 6) == Vec2u(42, 42));
    cr_assert(Vec2i(44, 12) * Vec2i(0, 2) == Vec2i(0, 24));
    cr_assert(Vec2d(423.4234, 123.323) * Vec2d(0.0, 0.0) == Vec2d(0.0, 0.0));
}

Test(Vector3, OperationMul)
{
    cr_assert(Vec3i(21, 11, 15) * 2 == Vec3i(42, 22, 30));
    cr_assert(Vec3u(6, 7, 10) * 7 == Vec3u(42, 49, 70));
    cr_assert(Vec3i(44, 12, 1) * 0 == Vec3i(0, 0, 0));
    cr_assert(Vec3d(423.4234, 123.323, 8888) * 0 == Vec3d(0.0, 0.0, 0.0));

    cr_assert(Vec3i(21, 11, 1) * Vec3i(2, 4, 42) == Vec3i(42, 44, 42));
    cr_assert(Vec3u(6, 7, 5) * Vec3u(7, 6, 5) == Vec3u(42, 42, 25));
    cr_assert(Vec3i(44, 12, 1) * Vec3i(0, 2, 12) == Vec3i(0, 24, 12));
    cr_assert(Vec3d(423.4234, 123.323, 943948.12323234) * Vec3d(0.0, 0.0, 1) == Vec3d(0.0, 0.0, 943948.12323234));
}