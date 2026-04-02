#pragma once
#include <string>
#include <iostream>

using namespace std;

class Goods {
private:
    string code;
    string name;
    double price;
    int quantity;

public:
    Goods();
    Goods(string c, string n, double p, int q);

    void setCode(string c);
    string getCode() const;

    void setName(string n);
    string getName() const;

    void setPrice(double p);
    double getPrice() const;

    void setQuantity(int q);
    int getQuantity() const;

    double calculateTotal() const;

    operator string() const;

    friend istream& operator>>(istream& in, Goods& g);
    friend ostream& operator<<(ostream& out, const Goods& g);
};