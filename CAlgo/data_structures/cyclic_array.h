#ifndef CYCLIC_ARRAY_H
#define CYCLIC_ARRAY_H

#include <cstdlib>

namespace Algo {

template <typename T>
class CyclicArray {
public:
    CyclicArray(size_t size)
        : m_size(size)
    {
        m_currentPosition = 0;
        m_data = new T[size];
    }

    void append(const T &val) {
        m_data[m_currentPosition] = val;
        next();
    }
    int count() const {
        return m_size;
    }

    T& operator[] (int index) {
        return m_data[index];
    }

private:
    void next() {
        m_currentPosition++;
        if(m_currentPosition >= m_size)
            m_currentPosition = 0;
    }

    size_t m_size;
    size_t m_currentPosition;
    T *m_data;
};

}
#endif // CYCLIC_ARRAY_H
