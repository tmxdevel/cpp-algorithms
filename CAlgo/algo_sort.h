#ifndef ALGO_SORT_H
#define ALGO_SORT_H

#include <functional>
#include <cstdlib>
#include <cstring>
#include "algo_utils.h"

namespace Algo {

template <typename T>
size_t partition(T *start, size_t size, std::function<bool(T*, T*)> less) {
    T pivot = *(start + size - 1);

    size_t result_idx = -1;

    for(T *p = start; p != start + size - 1; p++) {
        if(less(p, &pivot)) {
            result_idx++;
            AlgoUtils::swap_p(p, start+result_idx);
        }
    }

    AlgoUtils::swap_p(start + result_idx + 1, start + size - 1);
    return result_idx + 1;
}

template <typename T>
void merge(T *arr, size_t start, size_t mid, size_t end, std::function<bool(T*, T*)> less)
{
    size_t size = end;

    if(size < 3) {
        if (!less(arr, arr+1))
            AlgoUtils::swap_p(arr, arr+1);
        return;
    }

    T tmp_arr[size];

    memcpy(tmp_arr, arr, sizeof(T) * size);

    size_t size_part1 = mid - start;
    size_t size_part2 = end - mid;

    T *k = arr;
    T *i = tmp_arr;
    T *j = tmp_arr + size_part1;

    while (i != tmp_arr + size_part1 && j != tmp_arr + size) {
        if (less(i, j)) {
            *k = *i;
            i++;
        } else {
            *k = *j;
            j++;
        }
        k++;
    }

    while (i != tmp_arr + size_part1) {
        *k = *i;
        i++;
        k++;
    }

    while (j != tmp_arr + size) {
        *k = *j;
        j++;
        k++;
    }
}

template<typename T>
void bubble_sort(T *start, T *stop, std::function<bool(T*, T*)> less)
{
    size_t size = stop - start;
    for(int i = 0; i < size; i++) {
        for(T *p = start; p != stop-1; p++) {
            if(!less(p, p+1)) {
                AlgoUtils::swap_p(p, p+1);
            }
        }
    }
}

template<typename T>
void shaker_sort(T *start, T *stop, std::function<bool(T*, T*)> less)
{

    bool swapped = true;
    while(swapped) {
        swapped = false;
        for(T *p = start; p != stop-1; p++) {
            if(!less(p, p+1)) {
                AlgoUtils::swap_p(p, p+1);
                swapped = true;
            }
        }
        if(!swapped) break;
        swapped = false;
        for(T *p = stop; p != start+1; p--) {
            if(less(p, p-1)) {
                AlgoUtils::swap_p(p, p-1);
                swapped = true;
            }
        }
    }
}

template<typename T>
void merge_sort(T *start, T *stop, std::function<bool(T*, T*)> less)
{
    if(stop - start > 1) {
        size_t size = stop - start;
        T *mid = start + size/2;

        merge_sort(start, mid, less);
        merge_sort(mid, stop, less);
        merge(start, 0, size/2, size, less);
    }
}

template<typename T>
void quick_sort(T *start, T *stop, std::function<bool(T*, T*)> less)
{
    if(stop - start > 1) {

        size_t part = partition(start, stop - start, less);

        quick_sort(start, start + part, less);
        quick_sort(start + part, stop, less);
    }
}

}

#endif // ALGO_SORT_H
