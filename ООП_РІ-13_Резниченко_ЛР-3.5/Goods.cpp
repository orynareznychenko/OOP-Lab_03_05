#include "Goods.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Goods::Goods() {
    code = "N/A";
    name = "N/A";
    price = 0.0;
    quantity = 0;
}

Goods::Goods(string c, string n, double p, int q) {
    setCode(c);
    setName(n);
    setPrice(p);
    setQuantity(q);
}

void Goods::setCode(string c) {
    if (c.empty()) {
        cerr << "Error: Code cannot be empty!" << endl;
        exit(1);
    }
    code = c;
}

string Goods::getCode() const {
    return code;
}

void Goods::setName(string n) {
    if (n.empty()) {
        cerr << "Error: Name cannot be empty!" << endl;
        exit(1);
    }
    name = n;
}

string Goods::getName() const {
    return name;
}

void Goods::setPrice(double p) {
    if (p < 0) {
        cerr << "Error: Price cannot be negative!" << endl;
        exit(1);
    }
    price = p;
}

double Goods::getPrice() const {
    return price;
}

void Goods::setQuantity(int q) {
    if (q < 0) {
        cerr << "Error: Quantity cannot be negative!" << endl;
        exit(1);
    }
    quantity = q;
}

int Goods::getQuantity() const {
    return quantity;
}

double Goods::calculateTotal() const {
    return price * quantity;
}

Goods::operator string() const {
    return code + " " + name + " " + to_string(price) + " " + to_string(quantity);
}

istream& operator>>(istream& in, Goods& g) {
    string c, n;
    double p;
    int q;
    in >> c >> n >> p >> q;
    g.setCode(c);
    g.setName(n);
    g.setPrice(p);
    g.setQuantity(q);
    return in;
}

ostream& operator<<(ostream& out, const Goods& g) {
    out << string(g);
    return out;
}