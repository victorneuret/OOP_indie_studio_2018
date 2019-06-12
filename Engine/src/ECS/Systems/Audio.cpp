/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Audio.cpp
*/

#include <utility>
#include <iostream> // TODO: Remove

#include "Utils/Logger.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/Engine/ECS/Systems/SoundException.hpp"

Engine::ECS::System::Audio::Audio()
    : ASystem("Audio")
{}

void Engine::ECS::System::Audio::update(double)
{}

Engine::ECS::System::Audio::Sound Engine::ECS::System::Audio::loadSound(const std::string &key, const std::string &soundPath)
{
    if (isLoaded(key)) {
        Logger::getInstance().warning("Can't load sound \"" + key + "\": sound is already loaded.");
        return std::make_pair(nullptr, nullptr);
    }

    auto sound = std::make_shared<SoundObject>();
    auto buffer = std::make_shared<BufferObject>();
    auto pair = std::make_pair(buffer, sound);

    if (sound == nullptr || buffer == nullptr)
        throw MemoryException<Memory_Allocation_Failed>{"make_shared failed"};
    if (!buffer->loadFromFile(soundPath))
        throw SoundException<Sound_File_Not_Found>{"File Not Found: " + soundPath};

    sound->setBuffer(*buffer);
    _sounds.emplace(key, pair);

    return pair;
}

void Engine::ECS::System::Audio::unloadSound(const std::string &key)
{
    auto it = _sounds.find(key);

    if (it == _sounds.end()) {
        Logger::getInstance().warning("Can't unload sound \"" + key + "\": sound is not loaded.");
        return;
    }

    _sounds.erase(it);
}

Engine::ECS::System::Audio::Sound Engine::ECS::System::Audio::getSound(const std::string &key) const noexcept
{
    auto it = _sounds.find(key);

    if (it == _sounds.end())
        return std::make_pair(nullptr, nullptr);
    return it->second;
}

bool Engine::ECS::System::Audio::isLoaded(const std::string &key) const noexcept
{
    return getSound(key).second != nullptr;
}
