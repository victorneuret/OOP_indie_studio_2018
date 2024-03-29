/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Vec2
*/

#pragma once

#include <ostream>
#include <typeinfo>
#include <cmath>

namespace Engine::Math {
    template<typename T>
    class Vec2;

    using Vec2f = Vec2<float>;
    using Vec2d = Vec2<double>;
    using Vec2i = Vec2<int>;
    using Vec2u = Vec2<unsigned int>;
    using Vec2l = Vec2<long>;
}

template<typename T>
class Engine::Math::Vec2 {
public:
    T x{0};
    T y{0};

    Vec2<T>() noexcept;
    Vec2<T>(const Vec2<T> &vec) noexcept;
    Vec2<T>(const T &x, const T &y) noexcept;
    ~Vec2<T>() = default;

    Vec2<T> normalize() const noexcept;
    Vec2<T> &operator+=(const Vec2<T> &vec) noexcept;
    Vec2<T> &operator+=(const T &val) noexcept;
    Vec2<T> &operator-=(const Vec2<T> &vec) noexcept;
    Vec2<T> &operator-=(const T &val) noexcept;
    Vec2<T> &operator*=(const Vec2<T> &vec) noexcept;
    Vec2<T> &operator*=(const T &val) noexcept;
    Vec2<T> &operator/=(const Vec2<T> &vec);
    Vec2<T> &operator/=(const T &val);
    Vec2<T> operator+(const Vec2<T> &vec) const noexcept;
    Vec2<T> operator+(const T &val) const noexcept;
    Vec2<T> operator-(const Vec2<T> &vec) const noexcept;
    Vec2<T> operator-(const T &val) const noexcept;
    Vec2<T> operator*(const Vec2<T> &vec) const noexcept;
    Vec2<T> operator*(const T &val) const noexcept;
    Vec2<T> operator/(const Vec2<T> &vec) const;
    Vec2<T> operator/(const T &val) const;
    Vec2<T> &operator=(const Vec2<T> &vec) noexcept;
    Vec2<T> &operator=(const T &val) noexcept;
    bool operator==(const Vec2<T> &vec) const noexcept;
    bool operator!=(const Vec2<T> &vec) const noexcept;
};

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::normalize() const noexcept
{
    auto distance = static_cast<T>(std::sqrt(x * x + y * y));
    return Vec2<T>{x / distance, y / distance};
}

template<typename T>
Engine::Math::Vec2<T>::Vec2() noexcept
= default;

template<typename T>
Engine::Math::Vec2<T>::Vec2(const Vec2<T> &vec) noexcept
    : x{vec.x}, y{vec.y}
{}

template<typename T>
Engine::Math::Vec2<T>::Vec2(const T &x, const T &y) noexcept
    : x{x}, y{y}
{}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator+=(const Vec2<T> &vec) noexcept
{
    x += vec.x;
    y += vec.y;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator+=(const T &val) noexcept
{
    x += val;
    y += val;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator-=(const Vec2<T> &vec) noexcept
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator-=(const T &val) noexcept
{
    x -= val;
    y -= val;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator*=(const Vec2<T> &vec) noexcept
{
    x *= vec.x;
    y *= vec.y;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator*=(const T &val) noexcept
{
    x *= val;
    y *= val;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator/=(const Vec2<T> &vec)
{
    x /= vec.x;
    y /= vec.y;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator/=(const T &val)
{
    x /= val;
    y /= val;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator+(const Vec2<T> &vec) const noexcept
{
    return Vec2<T>{x + vec.x, y + vec.y};
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator+(const T &val) const noexcept
{
    return Vec2<T>{x + val, y + val};
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator-(const Vec2<T> &vec) const noexcept
{
    return Vec2<T>{x - vec.x, y - vec.y};
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator-(const T &val) const noexcept
{
    return Vec2<T>{x - val, y - val};
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator*(const Vec2<T> &vec) const noexcept
{
    return Vec2<T>{x * vec.x, y * vec.y};
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator*(const T &val) const noexcept
{
    return Vec2<T>{x * val, y * val};
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator/(const Vec2<T> &vec) const
{
    return Vec2<T>{x / vec.x, y / vec.y};
}

template<typename T>
Engine::Math::Vec2<T> Engine::Math::Vec2<T>::operator/(const T &val) const
{
    return Vec2<T>{x / val, y / val};
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator=(const Vec2<T> &vec) noexcept
{
    x = vec.x;
    y = vec.y;
    return *this;
}

template<typename T>
Engine::Math::Vec2<T> &Engine::Math::Vec2<T>::operator=(const T &val) noexcept
{
    x = val;
    y = val;
    return *this;
}

template<typename T>
bool Engine::Math::Vec2<T>::operator==(const Vec2<T> &vec) const noexcept
{
    return (x == vec.x && y == vec.y);
}

template<typename T>
bool Engine::Math::Vec2<T>::operator!=(const Vec2<T> &vec) const noexcept
{
    return !(vec == *this);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Engine::Math::Vec2<T> &rec)
{
    return out << "Vec2<" << typeid(T).name() << ">(" << rec.x << ", " << rec.y << ")";
}
