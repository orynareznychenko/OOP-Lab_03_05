#include "Receipt.h"
#include <sstream>
#include <cstdlib>

using namespace std;

Receipt::Receipt(string number, string dt) : Array<Goods>(0), receiptNumber(number), dateTime(dt) {}

void Receipt::setReceiptNumber(const string& number) {
    if (number.empty()) {
        cerr << "Error: Receipt number cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }
    receiptNumber = number;
}

void Receipt::setDateTime(const string& dt) {
    if (dt.empty()) {
        cerr << "Error: Date/Time cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }
    dateTime = dt;
}

void Receipt::addGoods(const Goods& g) {
    if (count >= MAX_SIZE) {
        cerr << "Error: Receipt is full (MAX_SIZE reached)!" << endl;
        exit(EXIT_FAILURE);
    }
    arr[count++] = g;
}

void Receipt::removeGoods(const string& code) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (arr[i].getCode() == code) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cerr << "Error during deletion: Product with code " << code << " not found!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = index; i < count - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    count--;
}

void Receipt::modifyGoods(const string& code, const Goods& newGoods) {
    for (int i = 0; i < count; ++i) {
        if (arr[i].getCode() == code) {
            arr[i] = newGoods;
            return;
        }
    }
    cerr << "Error during modification: Product with code " << code << " not found!" << endl;
    exit(EXIT_FAILURE);
}

Goods Receipt::searchGoods(const string& code) const {
    for (int i = 0; i < count; ++i) {
        if (arr[i].getCode() == code) {
            return arr[i];
        }
    }
    cerr << "Search error: Product with code " << code << " not found!" << endl;
    exit(EXIT_FAILURE);
    return Goods();
}

double Receipt::getTotalSum() const {
    double total = 0;
    for (int i = 0; i < count; ++i) {
        total += arr[i].calculateSum();
    }
    return total;
}

Receipt::operator string() const {
    ostringstream oss;
    oss << "=== Receipt No. " << receiptNumber << " ===" << endl;
    oss << "Date and time: " << dateTime << endl;
    oss << "-------------------------------------" << endl;
    for (int i = 0; i < count; ++i) {
        oss << string(arr[i]) << endl;
    }
    oss << "-------------------------------------" << endl;
    oss << "Total receipt sum: " << getTotalSum() << endl;
    oss << "=====================================";
    return oss.str();
}

istream& operator>>(istream& is, Receipt& r) {
    string num, dt;
    int itemsCount;
    cout << "Enter receipt number: ";
    is >> num;
    r.setReceiptNumber(num);
    cout << "Enter date and time (no spaces, e.g. 12.05.2023_14:00): ";
    is >> dt;
    r.setDateTime(dt);

    cout << "How many products to add? ";
    is >> itemsCount;
    if (itemsCount < 0) {
        cerr << "Error: Invalid number of products!" << endl;
        exit(EXIT_FAILURE);
    }

    r.count = 0;
    for (int i = 0; i < itemsCount; ++i) {
        Goods g;
        is >> g;
        r.addGoods(g);
    }
    return is;
}

ostream& operator<<(ostream& os, const Receipt& r) {
    os << string(r);
    return os;
}