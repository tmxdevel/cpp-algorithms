#include <iostream>
#include <vector>
#include <chrono>

#include <sys/time.h>

#include "algo_utils.h"
#include "algo_sort.h"
#include "algo_2d.h"
#include "testing/algobenchs.h"

using namespace std;

template <class Duration>
    using sys_time = std::chrono::time_point<std::chrono::system_clock, Duration>;
using sys_nanoseconds = sys_time<std::chrono::nanoseconds>;


bool lessInt(const float *lhs, const float *rhs) {
    return *lhs <= *rhs;
}

int main()
{
    AlgoBenchs b;

    return 0;
}
