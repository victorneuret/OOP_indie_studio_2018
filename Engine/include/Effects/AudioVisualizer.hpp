/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** AudioVisualizer.hpp
*/

#pragma once

#include <cstddef>
#include <complex>
#include <array>
#include <valarray>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class AudioVisualizer final {
public:
    static constexpr size_t BUFFER_SIZE = 8196;
    static constexpr double FREQ_MAX = 50000.0;
private:
    using Complex = std::complex<double>;
    using ComplexArray = std::valarray<Complex>;

    const sf::Sound &_sound;
    const sf::SoundBuffer &_buffer;

    ComplexArray _array{};
    std::array<double, BUFFER_SIZE> _scaleList{};

    struct SoundBufferData {
        decltype(_buffer.getChannelCount()) channelCount;
        decltype(_buffer.getSampleCount()) sampleCount;
        decltype(_buffer.getSampleRate()) sampleRate;

        SoundBufferData(decltype(_buffer.getChannelCount()) channelCount,
                        decltype(_buffer.getSampleCount()) sampleCount,
                        decltype(_buffer.getSampleRate()) sampleRate)
            : channelCount{channelCount}, sampleCount{sampleCount}, sampleRate{sampleRate}
        {}
    };

    struct VisualizationData {
        const double scaleAverage;
        const decltype(_scaleList) *scaleList;
    };

    const SoundBufferData _bufferData;

    void _fastFourierTransform(decltype(_array) &array)
    {
        const auto size = array.size();

        if (size < 2)
            return;

        auto even = decltype(_array)(array[std::slice(0, size / 2, 2)]);
        auto odd = decltype(_array)(array[std::slice(1, size / 2, 2)]);

        _fastFourierTransform(even);
        _fastFourierTransform(odd);

        for (decltype(array.size()) i = 0; i < size / 2; ++i) {
            Complex comp = std::polar(1.0, -2 * M_PI * i / size) * odd[i];
            array[i] = even[i] + comp;
            array[i + size / 2] = even[i] - comp;
        }
    }

    static void _smoothArray(std::array<double, BUFFER_SIZE> &data)
    {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it == data.begin())
                *it = (*it + *(it + 1)) / 2.0;
            else if (it == (data.end() - 1))
                *it = (*it + *(it - 1)) / 2.0;
            else
                *it = (*(it - 1) + *it + *(it + 1)) / 3.0;
        }
    }

public:
    AudioVisualizer(decltype(_sound) sound, decltype(_buffer) buffer)
        : _sound{sound}, _buffer{buffer},
          _bufferData{_buffer.getChannelCount(), _buffer.getSampleCount(),
                      _buffer.getSampleRate() * _buffer.getChannelCount()}
    {
        _array.resize(BUFFER_SIZE);
    }

    AudioVisualizer(const AudioVisualizer &) = delete;
    AudioVisualizer &operator=(const AudioVisualizer &) = delete;

    VisualizationData getVisualizationData()
    {
        const auto position = static_cast<size_t>(_sound.getPlayingOffset().asSeconds() * _bufferData.sampleRate);

        for (auto i = position; i - position < BUFFER_SIZE && i < _bufferData.sampleCount; ++i)
            _array[i - position] = Complex(_buffer.getSamples()[i], 0.0);

        _fastFourierTransform(_array);

        double sum = 0;

        size_t index = 0;
        for (auto &value : _array) {
            const auto abs = std::abs(value) / FREQ_MAX;

            sum += abs;
            _scaleList[index++] = abs;
        }

        _smoothArray(_scaleList);
        return VisualizationData{sum / _array.size(), &_scaleList};
    }
};