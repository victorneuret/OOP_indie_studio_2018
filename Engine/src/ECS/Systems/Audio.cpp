/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Audio.cpp
*/

#include <algorithm>

#include "Utils/Logger.hpp"
#include "ECS/Systems/Audio.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/Engine/ECS/Systems/SoundException.hpp"

void Engine::ECS::System::Audio::update(double)
{}

void Engine::ECS::System::Audio::loadSound(const std::string &key, const std::string &soundPath)
{
    if (isLoaded(key)) {
        Logger::getInstance().warning("Can't load sound \"" + key + "\": sound is already loaded.");
        return;
    }

    auto sound = std::make_shared<SoundType>();
    if (sound == nullptr)
        throw MemoryException<Memory_Allocation_Failed>{"make_shared failed"};

    BufferType buffer;
    if (!buffer.loadFromFile(soundPath))
        throw SoundException<Sound_File_Not_Found>{};

    sound->setBuffer(buffer);
    _sounds.emplace(key, sound);
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
    const auto it = _sounds.find(key);

    if (it == _sounds.cend())
        return nullptr;
    return it->second;
}

bool Engine::ECS::System::Audio::isLoaded(const std::string &key) const noexcept
{
    return getSound(key) != nullptr;
}
