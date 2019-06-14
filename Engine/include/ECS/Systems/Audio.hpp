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

class Engine::ECS::System::Audio final : public ASystem {
public:
    using BufferObject = sf::SoundBuffer;
    using SoundObject = sf::Sound;
    using Sound = std::pair<std::shared_ptr<BufferObject>, std::shared_ptr<SoundObject>>;
private:
    std::map<std::string, Sound> _sounds{};
public:
    Audio();
    ~Audio() override = default;

    void update(double dt) override;

    Sound loadSound(const std::string &key, const std::string &soundPath);
    void unloadSound(const std::string &key);
    Sound getSound(const std::string &sound) const noexcept;
    bool isLoaded(const std::string &key) const noexcept;
};
