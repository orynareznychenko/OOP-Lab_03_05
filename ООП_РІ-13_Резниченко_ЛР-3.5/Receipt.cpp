#include "Receipt.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Receipt::Receipt() : Array(), receiptNumber(""), date(""), time("") {}

Receipt::Receipt(string num, string d, string t) : Array(), receiptNumber(num), date(d), time(t) {}

Receipt::Receipt(string num, string d, string t, int size, const Goods& initVal)
    : Array(size, initVal), receiptNumber(num), date(d), time(t) {
}

void Receipt::setReceiptNumber(string num) {
    if (num.empty()) {
        cerr << "Error: Receipt number cannot be empty!" << endl;
        exit(1);
    }
    receiptNumber = num;
}

void Receipt::setDate(string d) {
    if (d.empty()) {
        cerr << "Error: Date cannot be empty!" << endl;
        exit(1);
    }
    date = d;
}

void Receipt::setTime(string t) {
    if (t.empty()) {
        cerr << "Error: Time cannot be empty!" << endl;
        exit(1);
    }
    time = t;
}

void Receipt::addGoods(const Goods& g) {
    if (count >= MAX_SIZE) {
        cerr << "Error: Receipt is full!" << endl;
        exit(1);
    }
    elements[count] = g;
    count++;
}

void Receipt::changeGoods(int index, const Goods& g) {
    rangeCheck(index);
    elements[index] = g;
}

void Receipt::deleteGoods(int index) {
    rangeCheck(index);
    for (int i = index; i < count - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    count--;
}

Goods Receipt::searchByCode(string c) const {
    for (int i = 0; i < count; ++i) {
        if (elements[i].getCode() == c) {
            return elements[i];
        }
    }
    cerr << "Error: Goods not found!" << endl;
    exit(1);
}

double Receipt::calculateTotalSum() const {
    double total = 0.0;
    for (int i = 0; i < count; ++i) {
        total += elements[i].calculateTotal();
    }
    return total;
}

Receipt& Receipt::operator=(const Receipt& other) {
    if (this != &other) {
        receiptNumber = other.receiptNumber;
        date = other.date;
        time = other.time;
        count = other.count;
        for (int i = 0; i < count; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

istream& operator>>(istream& in, Receipt& r) {
    string num, d, t;
    in >> num >> d >> t;
    r.setReceiptNumber(num);
    r.setDate(d);
    r.setTime(t);

    int itemsCount;
    in >> itemsCount;
    if (itemsCount < 0 || itemsCount > r.MAX_SIZE) {
        cerr << "Error: Invalid items count!" << endl;
        exit(1);
    }
    r.count = 0;
    for (int i = 0; i < itemsCount; ++i) {
        Goods g;
        in >> g;
        r.addGoods(g);
    }
    return in;
}

ostream& operator<<(ostream& out, const Receipt& r) {
    out << "Receipt: " << r.receiptNumber << " Date: " << r.date << " Time: " << r.time << "" << endl;
    for (int i = 0; i < r.count; ++i) {
        out << "- " << string(r.elements[i]) << "" << endl;
    }
    out << "Total Sum: " << r.calculateTotalSum() << "" << endl;
    return out;
}