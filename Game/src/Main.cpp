/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Main.hpp
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <complex>
#include <valarray>

#include "Logger.hpp"
#include "Utils/TypeDisplayer.hpp" // TODO: REMOVE
#include "GameApplication.hpp"
#include "BombermanApplication.hpp"

class AudioVisualizer final {
private:
    using Complex = std::complex<double>;
    using ComplexArray = std::valarray<Complex>;

    const sf::Sound &_sound;

    static constexpr size_t BUFFER_SIZE = 2048;
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

    static void _smoothArray(std::array<double, BUFFER_SIZE> &vec)
    {
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if (it == vec.begin())
                *it = (*it + *(it + 1)) / 2.0;
            else if (it == (vec.end() - 1))
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
            const auto abs = std::abs(value);

            sum += abs;
            _scaleList[index++] = abs;
        }

        _smoothArray(_scaleList);
        return VisualizationData{sum / _array.size() / 50000.0, &_scaleList};
    }
};

int main()
{
//    BombermanApplication app;
//
//    return app.run() ? APP_SUCCESS : APP_FAILURE;

    sf::RenderWindow win{sf::VideoMode{1600, 900}, "Audio Test"};
    sf::Event event{};

    win.setFramerateLimit(144);

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Yellow);
    circle.setRadius(25);
    circle.setOrigin(25, 25);
    circle.setPosition(win.getSize().x / 2.f, win.getSize().y / 2.f);

    sf::SoundBuffer buffer{};
    if (!buffer.loadFromFile("bp.ogg")) {
        std::cerr << "no" << std::endl;
        win.close();
    }

    sf::Sound sound{};
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.play();

    AudioVisualizer audioVisualizer{sound, buffer};

    double max = 0;
    while (win.isOpen()) {

        while (win.pollEvent(event))
            if (event.type == sf::Event::Closed)
                win.close();

        win.clear();

        auto visu = audioVisualizer.getVisualizationData();
        max = std::max(max, visu.scaleAverage);

        circle.setScale(visu.scaleAverage + 0.5, visu.scaleAverage + 0.5);

        win.draw(circle);
        win.display();
    }
    std::cout << "Max: " << max << std::endl;
}
