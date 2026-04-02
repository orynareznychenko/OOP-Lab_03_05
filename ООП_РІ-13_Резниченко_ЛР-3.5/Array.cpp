#include "Array.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= count) {
        cerr << "Error: Index out of range!" << endl;
        exit(1);
    }
}

Array::Array() {
    count = 0;
}

Array::Array(int size, const Goods& initialValue) {
    if (size < 0 || size > MAX_SIZE) {
        cerr << "Error: Invalid array size!" << endl;
        exit(1);
    }
    count = size;
    for (int i = 0; i < count; ++i) {
        elements[i] = initialValue;
    }
}

Goods& Array::operator[](int index) {
    rangeCheck(index);
    return elements[index];
}

const Goods& Array::operator[](int index) const {
    rangeCheck(index);
    return elements[index];
}