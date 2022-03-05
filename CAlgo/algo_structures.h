#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <cstdlib>

namespace Algo {

template<typename T>
struct Point2 {
    T x;
    T y;
};

typedef Point2<int32_t> Point2i;
typedef Point2<int64_t> Point2l;
typedef Point2<float> Point2f;
typedef Point2<double> Point2d;

struct AABB {
    Point2i topLeft;
    Point2i bottomRight;
};

}

#endif // STRUCTURES_H
