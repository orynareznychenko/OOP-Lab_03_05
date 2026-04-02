#pragma once
#include "Goods.h"

using namespace std;

class Array {
protected:
    static const int MAX_SIZE = 100;
    Goods elements[MAX_SIZE];
    int count;

    void rangeCheck(int index) const;

public:
    Array();
    Array(int size, const Goods& initialValue = Goods());

    Goods& operator[](int index);
    const Goods& operator[](int index) const;
};