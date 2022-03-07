#include "bechtimer.h"

#include <cstdio>

BechTimer::BechTimer()
{

}

void BechTimer::reset()
{
#ifdef LINUX_BENCH
    clock_gettime(CLOCK_REALTIME, &m_startTime);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &m_startTimeCpu);
#else
    m_startTime = std::chrono::system_clock::now();
#endif
}

void BechTimer::elapsed()
{
#ifdef LINUX_BENCH
    clock_gettime(CLOCK_REALTIME, &m_startTimeEnd);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &m_startTimeCpuEnd);
#else
    return (std::chrono::system_clock::now() - m_startTime).count();
#endif
}

time_t BechTimer::duration()
{
    time_t seconds = m_startTimeEnd.tv_sec - m_startTime.tv_sec;
    return (m_startTimeEnd.tv_nsec - m_startTime.tv_nsec) + seconds * 1000000000;
}

time_t BechTimer::durationCpu()
{
    time_t seconds = m_startTimeCpuEnd.tv_sec - m_startTimeCpu.tv_sec;
    return (m_startTimeCpuEnd.tv_nsec - m_startTimeCpu.tv_nsec) + seconds * 1000000000;
}
