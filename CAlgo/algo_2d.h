#ifndef ALGO_2D_H
#define ALGO_2D_H

#include <vector>
#include "algo_structures.h"

namespace Algo {

template <typename T>
Algo::Point2<T> nearest_point(const std::vector<Algo::Point2<T>> &points, T x, T y)
{
    Algo::Point2<T> res;
    T dist = -1;

    for(Algo::Point2<T> p : points) {
        T tmp = (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
        if(dist < 0) {
            dist = tmp;
            res = p;
            continue;
        }
        if(tmp < dist) {
            dist = tmp;
            res = p;
        }
    }
    return res;
}

template <typename T>
Algo::Point2<T> nearest_point_p(Algo::Point2<T> *points, size_t count, T x, T y)
{
    Algo::Point2<T> res;
    T dist = -1;

    for(auto p = points; p != points+count; p++) {
        T tmp = (x-p->x)*(x-p->x) + (y-p->y)*(y-p->y);
        if(dist < 0) {
            dist = tmp;
            res = *p;
            continue;
        }
        if(tmp < dist){
            dist = tmp;
            res = *p;
        }
    }
    return res;
}

}

#endif // ALGO_2D_H
