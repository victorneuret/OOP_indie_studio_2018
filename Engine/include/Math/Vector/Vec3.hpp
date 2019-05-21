/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Vec3
*/

#pragma once

#include <ostream>
#include <typeinfo>

namespace Engine::Math {
    class Vec3;
}

template <typename T>
class Vec3 {
public:
    using Vec3f = Vec3<float>;
    using Vec3d = Vec3<double>;
    using Vec3i = Vec3<int>;
    using Vec3u = Vec3<unsigned int>;
    using Vec3l = Vec3<long>;

    T x{0};
    T y{0};
    T z{0};

    Vec3<T>() noexcept;
    Vec3<T>(const Vec3<T> &vec) noexcept;
    Vec3<T>(const T &x, const T &y, const T &z) noexcept;
    ~Vec3<T>() = default;

    Vec3<T> &operator+=(const Vec3<T> &vec) noexcept;
    Vec3<T> &operator+=(const T &val) noexcept;
    Vec3<T> &operator-=(const Vec3<T> &vec) noexcept;
    Vec3<T> &operator-=(const T &val) noexcept;
    Vec3<T> &operator*=(const Vec3<T> &vec) noexcept;
    Vec3<T> &operator*=(const T &val) noexcept;
    Vec3<T> &operator/=(const Vec3<T> &vec);
    Vec3<T> &operator/=(const T &val);
    Vec3<T> operator+(const Vec3<T> &vec) const noexcept;
    Vec3<T> operator+(const T &val) const noexcept;
    Vec3<T> operator-(const Vec3<T> &vec) const noexcept;
    Vec3<T> operator-(const T &val) const noexcept;
    Vec3<T> operator*(const Vec3<T> &vec) const noexcept;
    Vec3<T> operator*(const T &val) const noexcept;
    Vec3<T> operator/(const Vec3<T> &vec) const;
    Vec3<T> operator/(const T &val) const;
    Vec3<T> &operator=(const Vec3<T> &vec) noexcept;
    Vec3<T> &operator=(const T &val) noexcept;
    bool operator==(const Vec3<T> &vec) const noexcept;
    bool operator!=(const Vec3<T> &vec) const noexcept;
};

template <typename T>
Vec3<T>::Vec3() noexcept
{}

template <typename T>
Vec3<T>::Vec3(const Vec3<T> &vec) noexcept
    : x{vec.x}, y{vec.y}, z{vec.z}
{}

template <typename T>
Vec3<T>::Vec3(const T &x, const T &y, const T &z) noexcept
    : x{x}, y{y}, z{z}
{}

template <typename T>
Vec3<T> &Vec3<T>::operator+=(const Vec3<T> &vec) noexcept
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator+=(const T &val) noexcept
{
    x += val;
    y += val;
    z += val;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator-=(const Vec3<T> &vec) noexcept
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator-=(const T &val) noexcept
{
    x -= val;
    y -= val;
    z -= val;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator*=(const Vec3<T> &vec) noexcept
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator*=(const T &val) noexcept
{
    x *= val;
    y *= val;
    z *= val;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator/=(const Vec3<T> &vec)
{
    x /= vec.x;
    y /= vec.y;
    z /= vec.z;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator/=(const T &val)
{
    x /= val;
    y /= val;
    z /= val;
    return *this;
}

template <typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T> &vec) const noexcept
{
    return Vec3<T>{x + vec.x, y + vec.y, z + vec.z};
}

template <typename T>
Vec3<T> Vec3<T>::operator+(const T &val) const noexcept
{
    return Vec3<T>{x + val, y + val, z + val};
}

template <typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T> &vec) const noexcept
{
    return Vec3<T>{x - vec.x, y - vec.y, z - vec.z};
}

template <typename T>
Vec3<T> Vec3<T>::operator-(const T &val) const noexcept
{
    return Vec3<T>{x - val, y - val, z - val};
}

template <typename T>
Vec3<T> Vec3<T>::operator*(const Vec3<T> &vec) const noexcept
{
    return Vec3<T>{x * vec.x, y * vec.y, z * vec.z};
}

template <typename T>
Vec3<T> Vec3<T>::operator*(const T &val) const noexcept
{
    return Vec3<T>{x * val, y * val, z * val};
}

template <typename T>
Vec3<T> Vec3<T>::operator/(const Vec3<T> &vec) const
{
    return Vec3<T>{x / vec.x, y / vec.y, z / vec.z};
}

template <typename T>
Vec3<T> Vec3<T>::operator/(const T &val) const
{
    return Vec3<T>{x / val, y / val, z / val};
}

template <typename T>
Vec3<T> &Vec3<T>::operator=(const Vec3<T> &vec) noexcept
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

template <typename T>
Vec3<T> &Vec3<T>::operator=(const T &val) noexcept
{
    x = val;
    y = val;
    z = val;
    return *this;
}

template <typename T>
bool Vec3<T>::operator==(const Vec3<T> &vec) const noexcept
{
    return (x == vec.x && y == vec.y && z == vec.z);
}

template <typename T>
bool Vec3<T>::operator!=(const Vec3<T> &vec) const noexcept
{
    return !(vec == *this);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Vec3<T> &rec)
{
    return out << "Vec3<" << typeid(T).name() << ">(" << rec.x << ", " << rec.y << ", " << rec.z << ")";
}
