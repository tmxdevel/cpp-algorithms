#ifndef BECHTIMER_H
#define BECHTIMER_H

#include <cstdint>
#include <chrono>

template <class Duration>
    using sys_time = std::chrono::time_point<std::chrono::system_clock, Duration>;
using sys_nanoseconds = sys_time<std::chrono::nanoseconds>;

class BechTimer
{
public:
    BechTimer();

    void reset();
    uint64_t elapsed();

private:
    sys_nanoseconds m_startTime;

};

#endif // BECHTIMER_H
