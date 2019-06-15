/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** ASerializable.hpp
*/

#pragma once

#include <map>
#include <ios>
#include <fstream>
#include <string>
#include <type_traits>

#include "Exception/SerializationException.hpp"

namespace Engine::Abstracts {
    class ASerializable;
}

class Engine::Abstracts::ASerializable {
protected:
    static std::map<std::string, std::fstream> _files;

    static std::fstream *getFileHandler(const std::string &path);

public:
    virtual ~ASerializable() = default;

    static void writeString(std::ostream &outStream, const std::string &str);

    template <typename T>
    static void writeAny(std::ostream &outStream, const T &val)
    {
        if (!outStream.good())
            throw SerializationException("Failed to write value.");
        outStream.write(reinterpret_cast<const char *>(&val), sizeof(T));
    }

    static const std::string readString(std::istream &inStream);

    template <typename T>
    static T readAny(std::istream &inStream)
    {
        T val{};

        if (!inStream.good())
            throw SerializationException("Failed to read value.");
        inStream.read(reinterpret_cast<char *>(&val), sizeof(T));
        return val;
    }

    virtual void pack(std::ostream &outStream) const = 0;
    virtual void unpack(std::istream &inStream) = 0;

    std::ostream &operator<<(std::ostream &outStream)
    {
        pack(outStream);
        return outStream;
    }

    std::istream &operator>>(std::istream &inStream)
    {
        unpack(inStream);
        return inStream;
    }
};
