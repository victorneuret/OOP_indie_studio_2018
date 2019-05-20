/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Logger.cpp
*/

#include <ctime>
#include <cstdio>
#include <cerrno>
#include <iomanip>
#include <sys/stat.h>
#include <sys/types.h>

#include "Logger.hpp"

std::unique_ptr<Engine::Logger> Engine::Logger::_instance{nullptr};

Engine::Logger::Logger()
{
    if (mkdir(LOG_FOLDER, 0755) != 0 && errno != EEXIST)
        throw std::runtime_error("Failed to create logs folder.");

    _path = LOG_FOLDER + _getDateFormatFile() + ".txt";
    _file = std::ofstream(_path);
}

Engine::Logger &Engine::Logger::getInstance()
{
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Logger>(new Logger);
        if (_instance == nullptr)
            throw std::runtime_error("Allocation Error");
    }
    return *_instance;
}

void Engine::Logger::print(Engine::Logger::Level level, const std::string &text, bool insertPrefix)
{
    std::lock_guard<std::mutex> lock{_mutex};
    const auto prefix = insertPrefix ? _getOutputPrefix(level) : "";

    _file << prefix << text << std::endl;
    std::cout << prefix << text << std::endl;
}

void Engine::Logger::info(const std::string &text, bool insertPrefix)
{
    return print(Level::INFO, text, insertPrefix);
}

void Engine::Logger::warning(const std::string &text, bool insertPrefix)
{
    return print(Level::WARNING, text, insertPrefix);
}

void Engine::Logger::error(const std::string &text, bool insertPrefix)
{
    return print(Level::ERROR, text, insertPrefix);
}

const std::string &Engine::Logger::getLogFilePath()
{
    return _path;
}

std::string Engine::Logger::_getDateFormat(const char *const format)
{
    auto t = std::time(nullptr);
    auto tm = std::localtime(&t);
    std::stringstream ss;

    ss << std::put_time(tm, format);
    return ss.str();
}

std::string Engine::Logger::_getDateFormatFile()
{
    return _getDateFormat(DATE_FORMAT_FILE);
}

std::string Engine::Logger::_getDateFormatOutput()
{
    return _getDateFormat(DATE_FORMAT_OUTPUT);
}

std::string Engine::Logger::_getPrefixFormat(Engine::Logger::Level level)
{
    switch (level) {
        case Level::INFO:
            return PREFIX_INFO;
        case Level::WARNING:
            return PREFIX_WARNING;
        case Level::ERROR:
            return PREFIX_ERROR;
        default:
            throw std::runtime_error("Not implemented.");
    }
}

std::string Engine::Logger::_getOutputPrefix(Engine::Logger::Level type)
{
    return "[" + _getDateFormatOutput() + "] " + _getPrefixFormat(type) + " ";
}
