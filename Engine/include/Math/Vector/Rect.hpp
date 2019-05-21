/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Rect
*/

#pragma once

#include <ostream>
#include <typeinfo>

#include "Math/Vector/Vec2.hpp"

namespace Engine::Math {
    template<typename T>
    class Rect;
}

template<typename T>
class Engine::Math::Rect {
public:
    using Rect_f = Rect<float>;
    using Rect_d = Rect<double>;
    using Rect_i = Rect<int>;
    using Rect_u = Rect<unsigned int>;
    using Rect_l = Rect<long>;

    T x{0};
    T y{0};
    T w{0};
    T h{0};

    Rect() noexcept;
    Rect(const Vec2<T> &pos, const Vec2<T> &size) noexcept;
    Rect(const T &x, const T &y, const T &w, const T &h) noexcept;
    ~Rect() = default;

    bool operator==(const Rect &rec) const noexcept;
    bool operator!=(const Rect &rec) const noexcept;
};

template<typename T>
Engine::Math::Rect<T>::Rect() noexcept
{}

template<typename T>
Engine::Math::Rect<T>::Rect(const Vec2<T> &pos, const Vec2<T> &size) noexcept
    : x{pos.x}, y{pos.y}, w{size.x}, h{size.y}
{}

template<typename T>
Engine::Math::Rect<T>::Rect(const T &x, const T &y, const T &w, const T &h) noexcept
    : x{x}, y{y}, w{w}, h{h}
{}

template<typename T>
bool Engine::Math::Rect<T>::operator==(const Rect &rec) const noexcept
{
    return (x == rec.x && y == rec.y && w == rec.w && h == rec.h);
}

template<typename T>
bool Engine::Math::Rect<T>::operator!=(const Rect &rec) const noexcept
{
    return !(rec == *this);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Engine::Math::Rect<T> &rec)
{
    return out << "Rect<" << typeid(T).name() << ">(" << rec.x << ", " << rec.y << ", " << rec.w << ", " << rec.h << ")";
}
