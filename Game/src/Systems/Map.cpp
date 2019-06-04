/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** MapSystem.cpp
*/

#include <algorithm>
#include <iostream>

#include "Systems/Map.hpp"
#include "Utils/Random.hpp"

void Game::System::Map::_createFirstSquare() noexcept
{
    std::string str;
    uint64_t randomValue = 0;

    for (size_t i = 0; i < (MAP_HEIGHT + (MAP_HEIGHT % 2)) / 2; i++) {
        str.clear();

        for (size_t iChar = 0; iChar < (MAP_WIDTH + (MAP_WIDTH % 2)) / 2; iChar++) {
            randomValue = Random::getUnsigned(0, 5);
            switch (randomValue) {
                case 0: str.append("0"); break;
                case 1: str.append("#"); break;
                default: str.append(".");
            }
        }

        if (_map.size() == 0) {
            str[0] = '0';
            str[1] = '0';
        } else if (_map.size() == 1) {
            str[0] = '0';
        }

        _map.push_back(str);
    }
}

void Game::System::Map::_duplicateWidth() noexcept
{
    std::string copy;

    for (auto &elem : _map) {
        copy.clear();
        copy.append(elem);
        std::reverse(copy.begin(), copy.end());
        elem.append(copy);
    }
}

void Game::System::Map::_duplicateHeight() noexcept
{
    decltype(_map) mapCopy = _map;

    std::reverse(mapCopy.begin(), mapCopy.end());
    for (const auto &elem : mapCopy)
        _map.push_back(elem);
}


void Game::System::Map::_createMap(std::vector<std::shared_ptr<Engine::ECS::IEntity>> &) noexcept
{
    _createFirstSquare();
    _duplicateWidth();
    _duplicateHeight();

    for (const auto &elem : _map)
        std::cout << elem << std::endl;
}

void Game::System::Map::update(double, std::vector<std::shared_ptr<Engine::ECS::IEntity>> &entities)
{
    if (_map.empty())
        _createMap(entities);
}