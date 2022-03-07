#ifndef ALGOBENCHS_H
#define ALGOBENCHS_H

#include <vector>

#include "algo_utils.h"
#include "algo_sort.h"
#include "algo_2d.h"
#include "bechtimer.h"

class AlgoBenchs
{
public:
    AlgoBenchs();

    void testPoints(int iterations);
    void testPointsPtr(int iterations);

    void testIntSort(int iterations);
    void testLongSort(int iterations);
    void testFloatSort(int iterations);
    void testDoubleSort(int iterations);

    void print(uint64_t time, int iterations);

private:
    BechTimer m_timer;
    Algo::AABB m_bounds;

    std::vector<Algo::Point2i> m_intPoints;
    std::vector<Algo::Point2l> m_longPoints;
    std::vector<Algo::Point2f> m_floatPoints;
    std::vector<Algo::Point2d> m_doublePoints;

    std::vector<int32_t> m_randInt;
    std::vector<int64_t> m_randLong;
    std::vector<float> m_randFloat;
    std::vector<double> m_randDouble;

};

#endif // ALGOBENCHS_H
