/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ASerializable.cpp
*/

#include <vector>
#include <filesystem>

#include "Exception/SerializationException.hpp"
#include "Abstracts/ASerializable.hpp"

decltype(Engine::Abstracts::ASerializable::_files) Engine::Abstracts::ASerializable::_files{};

std::fstream *Engine::Abstracts::ASerializable::getFileHandler(const std::string &path)
{
    auto file = _files.find(path);

    if (file == _files.end()) {
        _files[path] = std::fstream{path, std::ios::in | std::ios::out | std::ios::app | std::ios::binary};
        return &_files[path];
    }

    return &file->second;
}

void Engine::Abstracts::ASerializable::removeAll()
{
    for (auto &file : _files) {
        try {
            std::filesystem::remove(file.first);
            file.second.close();
        } catch (...) {}
    }

    _files.clear();
}

void Engine::Abstracts::ASerializable::writeString(std::ostream &outStream, const std::string &str)
{
    size_t size = str.size();

    try {
        outStream.write(reinterpret_cast<const char *>(&size), sizeof(decltype(size)));
        outStream << str;
    } catch (const std::istream::failure &) {
        throw SerializationException("Failed to write string.");
    }
}

const std::string Engine::Abstracts::ASerializable::readString(std::istream &inStream)
{
    size_t size{0};

    try {
        inStream.read(reinterpret_cast<char *>(&size), sizeof(size_t));
    } catch (const std::istream::failure &) {
        throw SerializationException("Failed to read string.");
    }

    if (size == 0)
        return {};

    std::vector<char> buffer(size);

    inStream.read(&buffer[0], static_cast<long>(size));
    return std::string().assign(&buffer[0], size);
}
