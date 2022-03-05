#include "bechtimer.h"

BechTimer::BechTimer()
{

}

void BechTimer::reset()
{
    m_startTime = std::chrono::system_clock::now();
}

uint64_t BechTimer::elapsed()
{
    return (std::chrono::system_clock::now() - m_startTime).count();
}
