/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Random.hpp
*/

#pragma once

#include <random>
#include <cstdint>

class Random final {
public:
    Random() = delete;
    Random(const Random &) = delete;
    Random &operator=(const Random &other) = delete;

    static double range();
    static double getDouble(double min, double max);
    static int64_t getSigned(int64_t min, int64_t max);
    static uint64_t getUnsigned(uint64_t min, uint64_t max);
    static bool getBool();
private:
    static std::random_device _randomDevice;
    static std::mt19937 _gen;
    static std::uniform_real_distribution<> _distribution;
};

