/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Audio.hpp
*/

#pragma once

#include <map>
#include <string>
#include <memory>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "ECS/Abstracts/ASystem.hpp"

namespace Engine::ECS::System {
    class Audio;
}

class Engine::ECS::System::Audio final : public ASystem<Audio> {
public:
    using BufferType = sf::SoundBuffer;
    using SoundType = sf::Sound;
    using Sound = std::shared_ptr<SoundType>;
private:
    std::map<std::string, Sound> _sounds{};
public:
    Audio();
    ~Audio() override = default;

    void update(double dt) override;

    void loadSound(const std::string &key, const std::string &soundPath);
    void unloadSound(const std::string &key);
    Sound getSound(const std::string &sound) const noexcept;
    bool isLoaded(const std::string &key) const noexcept;
};
