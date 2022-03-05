#include "algobenchs.h"
#include <iostream>


AlgoBenchs::AlgoBenchs()
{
    int iterations = 10000;
    size_t size = 10000;
    m_bounds.topLeft = {-100, -100};
    m_bounds.bottomRight = {100, 100};

    m_intPoints = AlgoUtils::gen_random_points<int32_t>(m_bounds, size);
    m_longPoints = AlgoUtils::gen_random_points<int64_t>(m_bounds, size);
    m_floatPoints = AlgoUtils::gen_random_points<float>(m_bounds, size);
    m_doublePoints = AlgoUtils::gen_random_points<double>(m_bounds, size);

    testPoints(iterations);
}

void AlgoBenchs::testPoints(int iterations)
{
    auto intPoints = m_intPoints;
    auto longPoints = m_longPoints;
    auto floatPoints = m_floatPoints;
    auto doublePoints = m_doublePoints;

    m_timer.reset();
    for(int i = 0; i < iterations; i++) {
        Algo::nearest_point<int32_t>(intPoints, 0, 0);
    }
    auto time = m_timer.elapsed();
    print(time, iterations);

    m_timer.reset();
    for(int i = 0; i < iterations; i++) {
        Algo::nearest_point<int64_t>(longPoints, 0, 0);
    }
    time = m_timer.elapsed();
    print(time, iterations);

    m_timer.reset();
    for(int i = 0; i < iterations; i++) {
        Algo::nearest_point<float>(floatPoints, 0, 0);
    }
    time = m_timer.elapsed();
    print(time, iterations);

    m_timer.reset();
    for(int i = 0; i < iterations; i++) {
        Algo::nearest_point<double>(doublePoints, 0, 0);
    }
    time = m_timer.elapsed();
    print(time, iterations);
}

void AlgoBenchs::print(uint64_t time, int iterations)
{
    std::cout << "Time passed(" << iterations << " iterations): "
              << time << "ns. (" << time/iterations
              << "ns per iteration)" << std::endl
              << "===============" << std::endl;
}

