/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Logger.cpp
*/

#define _CRT_SECURE_NO_DEPRECATE

#include <ctime>
#include <cerrno>
#include <iomanip>
#if defined _MSC_VER
    #include <direct.h>
#elif defined __GNUC__
    #include <sys/stat.h>
#endif

#include "Utils/Logger.hpp"
#include "Exception/NotImplementedException.hpp"
#include "Exception/Memory/MemoryException.hpp"
#include "Exception/Permission/PermissionException.hpp"

std::unique_ptr<Engine::Logger> Engine::Logger::_instance{nullptr};

Engine::Logger::Logger()
{
#if defined _MSC_VER
    int err = _mkdir(LOG_FOLDER);
#elif defined __GNUC__
    int err = mkdir(LOG_FOLDER, 0755);
#endif
    if (err != 0 && errno != EEXIST)
        throw PermissionException<Permission_Denied>("Cannot create log folder.");

    _path = LOG_FOLDER + _getDateFormatFile() + ".txt";
    _file = std::ofstream(_path);
}

Engine::Logger &Engine::Logger::getInstance()
{
    if (_instance == nullptr) {
        _instance = std::unique_ptr<Logger>(new Logger);
        if (_instance == nullptr)
            throw MemoryException<Memory_Allocation_Failed>("Could not create logger instance.");
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
            throw NotImplementedException("Logger::_getPrefixFormat");
    }
}

std::string Engine::Logger::_getOutputPrefix(Engine::Logger::Level type)
{
    return "[" + _getDateFormatOutput() + "] " + _getPrefixFormat(type) + " ";
}
