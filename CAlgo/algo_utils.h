#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <cstdlib>

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

}
#endif // UTILS_H
