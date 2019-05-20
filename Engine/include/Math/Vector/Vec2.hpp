/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Vec2
*/

#pragma once

namespace Engine::Math {
	class Vec2;
}

template<typename T>
class Vec2 {
public:
	T x{0};
	T y{0};

	Vec2<T>() noexcept;
	Vec2<T>(const Vec2<T> &vec) noexcept;
	Vec2<T>(const T &x, const T &y) noexcept;
	~Vec2<T>() = default;

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
Vec2<T>::Vec2() noexcept
{
	x = 0;
	y = 0;
}

template<typename T>
Vec2<T>::Vec2(const Vec2<T> &vec) noexcept
{
	x = vec.x;
	y = vec.y;
}

template<typename T>
Vec2<T>::Vec2(const T &x, const T &y) noexcept
{
	x = x;
	y = y;
}

template<typename T>
Vec2<T> &Vec2<T>::operator+=(const Vec2<T> &vec) noexcept
{
	x += vec.x;
	y += vec.y;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator+=(const T &val) noexcept
{
	x += val;
	y += val;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator-=(const Vec2<T> &vec) noexcept
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator-=(const T &val) noexcept
{
	x -= val;
	y -= val;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator*=(const Vec2<T> &vec) noexcept
{
	x *= vec.x;
	y *= vec.y;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator*=(const T &val) noexcept
{
	x *= val;
	y *= val;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator/=(const Vec2<T> &vec)
{
	x /= vec.x;
	y /= vec.y;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator/=(const T &val)
{
	x /= val;
	y /= val;
}

template<typename T>
Vec2<T> Vec2<T>::operator+(const Vec2<T> &vec) const noexcept
{
	return Vec2<T>{*this} += vec;
}

template<typename T>
Vec2<T> Vec2<T>::operator+(const T &val) const noexcept
{
	return Vec2<T>{*this} += val;
}

template<typename T>
Vec2<T> Vec2<T>::operator-(const Vec2<T> &vec) const noexcept
{
	return Vec2<T>{*this} -= vec;
}

template<typename T>
Vec2<T> Vec2<T>::operator-(const T &val) const noexcept
{
	return Vec2<T>{*this} -= val;
}

template<typename T>
Vec2<T> Vec2<T>::operator*(const Vec2<T> &vec) const noexcept
{
	return Vec2<T>{*this} *= vec;
}

template<typename T>
Vec2<T> Vec2<T>::operator*(const T &val) const noexcept
{
	return Vec2<T>{*this} *= val;
}

template<typename T>
Vec2<T> Vec2<T>::operator/(const Vec2<T> &vec) const
{
	return Vec2<T>{*this} /= vec;
}

template<typename T>
Vec2<T> Vec2<T>::operator/(const T &val) const
{
	return Vec2<T>{*this} /= val;
}

template<typename T>
Vec2<T> &Vec2<T>::operator=(const Vec2<T> &vec) noexcept
{
	x = vec.x;
	y = vec.y;
	return *this;
}

template<typename T>
Vec2<T> &Vec2<T>::operator=(const T &val) noexcept
{
	x = val;
	y = val;
	return *this;
}

template<typename T>
bool Vec2<T>::operator==(const Vec2<T> &vec) const noexcept
{
	return (x == vec.x && y == vec.y);
}

template<typename T>
bool Vec2<T>::operator!=(const Vec2<T> &vec) const noexcept
{
	return (x != vec.x || y != vec.y);
}

using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;
using Vec2i = Vec2<int>;
using Vec2u = Vec2<unsigned int>;
using Vec2l = Vec2<long>;