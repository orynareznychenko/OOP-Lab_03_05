#pragma once
#include "Array.h"
#include <string>

using namespace std;

class Receipt : public Array {
private:
    string receiptNumber;
    string date;
    string time;

public:
    Receipt();
    Receipt(string num, string d, string t);
    Receipt(string num, string d, string t, int size, const Goods& initVal);

    void setReceiptNumber(string num);
    void setDate(string d);
    void setTime(string t);

    void addGoods(const Goods& g);
    void changeGoods(int index, const Goods& g);
    void deleteGoods(int index);
    Goods searchByCode(string c) const;
    double calculateTotalSum() const;

    Receipt& operator=(const Receipt& other);

    friend istream& operator>>(istream& in, Receipt& r);
    friend ostream& operator<<(ostream& out, const Receipt& r);
};