#ifndef BECHTIMER_H
#define BECHTIMER_H

#include <cstdint>
#include <chrono>

#define LINUX_BENCH

#ifdef LINUX_BENCH
    #include <time.h>
#else
template <class Duration>
    using sys_time = std::chrono::time_point<std::chrono::system_clock, Duration>;
using sys_nanoseconds = sys_time<std::chrono::nanoseconds>;
#endif

class BechTimer
{
public:
    BechTimer();

    void reset();
    void elapsed();
    time_t duration();
    time_t durationCpu();

private:
#ifdef LINUX_BENCH
    timespec m_startTime;
    timespec m_startTimeCpu;
    timespec m_startTimeEnd;
    timespec m_startTimeCpuEnd;
#else
    sys_nanoseconds m_startTime;
#endif

};

#endif // BECHTIMER_H
