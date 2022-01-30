#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "ILogger.h"
#include"Macros.h"
#include <mutex>

#define DLL_EXPORT _declspec(dllexport)
#define LOGGER_LOCK std::lock_guard<std::mutex> lock(ConsoleLogger::mLock);

class  ConsoleLogger :
    public ILogger
{
public:
    static std::mutex  mLock;

public:
    static auto getCurrentTime();

    static DLL_EXPORT void trace(const char* msg);;
    static DLL_EXPORT void info(const char* msg);;
    static DLL_EXPORT void warning(const char* msg);;
    static DLL_EXPORT void error(const char* msg);
};


#ifdef _DEBUG

#define TRACE(x) ConsoleLogger::trace(x);

#define INFO(x) ConsoleLogger::info(x);

#define WARNING(x) ConsoleLogger::warning(x);

#define ERROR(x) ConsoleLogger::error(x);

#else
#define TRACE(x)

#define INFO(x) 

#define WARNING(x)

#define ERROR(x) 

#endif // DEBUG



