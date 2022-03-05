#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <cstdlib>

#include "algo_structures.h"

namespace AlgoUtils {

template<typename T>
T gen_random(T min, T max)
{
    double aspectRatio = static_cast<double>(max - min)/RAND_MAX;
    return min + rand() * aspectRatio;
}

template<typename T>
std::vector<T> gen_random_list(size_t size, T min, T max)
{
    std::vector<T> result(size);

    for(size_t i = 0; i < size; i++) {
        result[i] = gen_random(max, min);
    }

    return result;
}

template<typename T>
void swap_p(T* left, T* right)
{
    T temp = *left;
    *left = *right;
    *right = temp;
}

template<typename T>
Algo::Point2<T> gen_random_point(const Algo::AABB &bounds)
{
    Algo::Point2<T> res;
    res.x = gen_random<T>(bounds.topLeft.x,bounds.bottomRight.x);
    res.y = gen_random<T>(bounds.topLeft.y,bounds.bottomRight.y);
    return res;
}

template<typename T>
std::vector<Algo::Point2<T>> gen_random_points(const Algo::AABB &bounds, size_t count)
{
    std::vector<Algo::Point2<T>> res(count);
    for(size_t i = 0; i < count; i++) {
        res[i] = gen_random_point<T>(bounds);
    }
    return res;
}

}
#endif // UTILS_H
