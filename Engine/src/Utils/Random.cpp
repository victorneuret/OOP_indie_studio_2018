/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Random.cpp
*/

#if defined _MSC_VER
#pragma warning(disable:4244)
// Disables "Conversion from 'x' to 'y', possible loss of data"
//      -> No data loss possible in this file.
#endif

#include <cmath>

#include "Utils/Random.hpp"

std::random_device Random::_randomDevice{};
std::mt19937 Random::_gen{_randomDevice()};
std::uniform_real_distribution<> Random::_distribution{0.0, 1.0};

double Random::range()
{
    return _distribution(_gen);
}

double Random::getDouble(double min, double max)
{
    return (max - min) * range() + min;
}

int64_t Random::getSigned(int64_t min, int64_t max)
{
    return static_cast<int64_t>(std::roundl(getDouble(min, max)));
}

uint64_t Random::getUnsigned(uint64_t min, uint64_t max)
{
    return static_cast<uint64_t>(std::roundl(getDouble(min, max)));
}

bool Random::getBool()
{
    return getUnsigned(0, 1);
}
