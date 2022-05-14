#include "Backend/timer.h"

void Timer::start() {
    m_start = std::chrono::system_clock::now();
    m_run = true;
}

void Timer::stop() {
    m_end = std::chrono::system_clock::now();
    m_run = false;
}

double Timer::elapsedMilliseconds() {
    std::chrono::time_point<std::chrono::system_clock> end;
    if (m_run) {
        end = std::chrono::system_clock::now();
    }
    else {
        end = m_end;
    }
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start).count();
}

double Timer::elapsedSeconds() {
    return elapsedMilliseconds() / 1000.0;
}