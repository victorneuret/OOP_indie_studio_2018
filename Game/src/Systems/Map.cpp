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

void Game::System::Map::_createMap(std::vector<std::shared_ptr<Engine::ECS::IEntity>> &) noexcept
{
    std::string widthString;
    std::string halfWidthString;
    uint64_t randomValue = 0;
    decltype(_map) mapCopy;

    for (size_t i = 0; i < (MAP_HEIGHT + (MAP_HEIGHT % 2)) / 2; i++) {
        widthString.clear();
        halfWidthString.clear();

        for (size_t iChar = 0; iChar < (MAP_WIDTH + (MAP_WIDTH % 2)) / 2; iChar++) {
            randomValue = Random::getUnsigned(0, 5);
            switch (randomValue) {
                case 0: widthString.append("0"); break;
                case 1: widthString.append("#"); break;
                default: widthString.append(".");
            }
        }

        if (_map.size() == 0) {
            widthString[0] = '0';
            widthString[1] = '0';
        } else if (_map.size() == 1) {
            widthString[0] = '0';
        }

        halfWidthString.append(widthString);
        std::reverse(halfWidthString.begin(), halfWidthString.end());
        widthString.append(halfWidthString);

        _map.push_back(widthString);
    }
    mapCopy = _map;
    std::reverse(mapCopy.begin(), mapCopy.end());
    for (const auto &elem : mapCopy)
        _map.push_back(elem);

    for (const auto &elem : _map)
        std::cout << elem << std::endl;
}

void Game::System::Map::update(double, std::vector<std::shared_ptr<Engine::ECS::IEntity>> &entities)
{
    if (_map.empty())
        _createMap(entities);
}