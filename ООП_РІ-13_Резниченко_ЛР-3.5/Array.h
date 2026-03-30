#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>

template <class T>
class Array {
protected:
    static const int MAX_SIZE = 100;
    T arr[MAX_SIZE];
    int count;

    void rangeCheck(int index) const {
        if (index < 0 || index >= count) {
            std::cerr << "Error: Array index out of bounds! (Index: " << index << ")" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

public:
    Array(int size = 0, const T& defaultValue = T()) {
        if (size < 0 || size > MAX_SIZE) {
            std::cerr << "Error: Invalid array size!" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        count = size;
        for (int i = 0; i < count; ++i) {
            arr[i] = defaultValue;
        }
    }

    T& operator[](int index) {
        rangeCheck(index);
        return arr[index];
    }

    const T& operator[](int index) const {
        rangeCheck(index);
        return arr[index];
    }

    int getCount() const { return count; }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            count = other.count;
            for (int i = 0; i < count; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
};

#endif 