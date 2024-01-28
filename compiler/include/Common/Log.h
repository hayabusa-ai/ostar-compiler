#pragma once
#include <iostream>
#include <vector>

namespace ostar {

enum class LogLevel : uint32_t {
    DEBUG = 0,
    INFO = 1, 
    WARN = 2,  
    ERROR = 3,
};

void SetLogLevel(LogLevel);

void setAssertThrow(bool);

LogLevel GetLogLevel();

class Log {
public:
    Log(LogLevel level = LogLevel::DEBUG) : mCurrLevle(level) {}

    static Log debug();
    static Log info();
    static Log warning();
    static Log error();

    template <typename T>
    Log& operator<<(const T& value) {
        if (mCurrLevle >= GetLogLevel()) {
            std::cerr << value << std::flush;
        }
        return *this;
    }

    template <typename T>
    Log& operator<<(const std::vector<T>& value) {
        if (mCurrLevle >= GetLogLevel()) {
            std::cerr << "[";
            for (size_t i = 0; i < value.size(); i++) {
                if (i != 0)
                    std::cerr << ",";
                std::cerr << value[i];
            }
            std::cerr << "]" << std::flush;
        }
        return *this;
    }

private:
    LogLevel mCurrLevle = LogLevel::DEBUG;
};

class LogFatal : public Log {
public:
    LogFatal();
    ~LogFatal();
};

#define LOG_DEBUG ostar::Log::debug()
#define LOG_INFO  ostar::Log::info()
#define LOG_WARN  ostar::Log::warning()
#define LOG_ERROR ostar::Log::error()

#define CC_ASSERT(expr)                                                              \
    if (!(expr))                                                                     \
    ostar::LogFatal() << "Ostar Assert " << #expr << " Error, in file: " << __FILE__ \
                      << ":" << __LINE__ << ", at function: " << __PRETTY_FUNCTION__ \
                      << ", line: " << __LINE__ << ". extra message: "

//! in order to destruct LogFatal after message is print, add `if(true)`
#define CC_ABORT                                                                       \
    if (true)                                                                          \
    ostar::LogFatal() << "Ostar Aborting, Error in file: " << __FILE__ << ":" << __LINE__ \
                      << ", at function: " << __PRETTY_FUNCTION__                      \
                      << ", line: " << __LINE__ << ". extra message: "

}  

