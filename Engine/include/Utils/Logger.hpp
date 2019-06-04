/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** Logger.hpp
*/

#pragma once

#include <mutex>
#include <memory>
#include <fstream>
#include <iostream>

constexpr const char *const LOG_FOLDER = "./logs/";

constexpr const char *const DATE_FORMAT_OUTPUT = "%c";
constexpr const char *const DATE_FORMAT_FILE = "%Y-%m-%d_%H:%M:%S";

constexpr const char *const PREFIX_INFO = "[INFO] ";
constexpr const char *const PREFIX_WARNING = "[WARN] ";
constexpr const char *const PREFIX_ERROR = "[ERROR]";

namespace Engine {
    class Logger final {
    public:
        enum class Level {
            INFO,
            WARNING,
            ERROR
        };

        static Logger &getInstance();
        ~Logger() = default;

        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;

        void print(Level level, const std::string &text, bool insertPrefix = true);
        void info(const std::string &text, bool insertPrefix = true);
        void warning(const std::string &text, bool insertPrefix = true);
        void error(const std::string &text, bool insertPrefix = true);

        const std::string &getLogFilePath();
    private:
        Logger();

        std::string _path{};
        std::ofstream _file{};
        std::mutex _mutex{};

        static std::unique_ptr<Logger> _instance;

        static std::string _getPrefixFormat(Level level);
        static std::string _getOutputPrefix(Engine::Logger::Level type);
        static std::string _getDateFormat(const char *format);
        static std::string _getDateFormatFile();
        static std::string _getDateFormatOutput();
    };
}
