#include "Goods.h"
#include <sstream>
#include <cstdlib>

using namespace std;

Goods::Goods(string c, string n, double p, int q) {
    setCode(c);
    setName(n);
    setPrice(p);
    setQuantity(q);
}

void Goods::setCode(const string& c) {
    if (c.empty()) {
        cerr << "Error: Product code cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }
    code = c;
}

void Goods::setName(const string& n) {
    if (n.empty()) {
        cerr << "Error: Product name cannot be empty!" << endl;
        exit(EXIT_FAILURE);
    }
    name = n;
}

void Goods::setPrice(double p) {
    if (p <= 0) {
        cerr << "Error: Product price must be greater than 0!" << endl;
        exit(EXIT_FAILURE);
    }
    price = p;
}

void Goods::setQuantity(int q) {
    if (q < 0) {
        cerr << "Error: Product quantity cannot be negative!" << endl;
        exit(EXIT_FAILURE);
    }
    quantity = q;
}

string Goods::getCode() const { return code; }
string Goods::getName() const { return name; }
double Goods::getPrice() const { return price; }
int Goods::getQuantity() const { return quantity; }

double Goods::calculateSum() const {
    return price * quantity;
}

Goods::operator string() const {
    ostringstream oss;
    oss << "[Code: " << code << " | Name: " << name
        << " | Price: " << price << " | Quantity: " << quantity
        << " | Sum: " << calculateSum() << "]";
    return oss.str();
}

istream& operator>>(istream& is, Goods& g) {
    string c, n;
    double p;
    int q;
    cout << "Enter product code, name, price, and quantity (separated by space): ";
    is >> c >> n >> p >> q;
    g.setCode(c);
    g.setName(n);
    g.setPrice(p);
    g.setQuantity(q);
    return is;
}

ostream& operator<<(ostream& os, const Goods& g) {
    os << string(g);
    return os;
}