#include "ConsoleLogger.h"

std::mutex ConsoleLogger::mLock;

auto ConsoleLogger::getCurrentTime()
{
    std::time_t const now_c = std::time(NULL);
#pragma warning(disable : 4996)
    return std::put_time(std::localtime(&now_c), "%F %T");
}

void ConsoleLogger::trace(const char* msg) { LOGGER_LOCK std::cout << RESET << getCurrentTime() << " [Trace]   " << msg << RESET << std::endl; }

void ConsoleLogger::info(const char* msg) { LOGGER_LOCK std::cout << BOLDCYAN << getCurrentTime() << " [Info]    " << msg << RESET << std::endl; }

void ConsoleLogger::warning(const char* msg) { LOGGER_LOCK std::cout << BOLDYELLOW << getCurrentTime() << " [Warning] " << msg << RESET << std::endl; }

void ConsoleLogger::error(const char* msg) { LOGGER_LOCK std::cout << BOLDRED << getCurrentTime() << " [Error]   " << msg << RESET << std::endl; }
