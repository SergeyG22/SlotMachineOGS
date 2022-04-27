#pragma once
#include <chrono>
#include <functional>
#include <thread>

class Timer {
    std::chrono::time_point<std::chrono::system_clock> m_start;
    std::chrono::time_point<std::chrono::system_clock> m_end;
    bool m_run = false;
public:
    void start();
    void stop();
    double elapsedMilliseconds();
    double elapsedSeconds();
};
