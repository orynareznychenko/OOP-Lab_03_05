#ifndef GOODS_H
#define GOODS_H

#include <string>
#include <iostream>

class Goods {
private:
    std::string code;
    std::string name;
    double price;
    int quantity;

public:
    Goods(std::string c = "0000", std::string n = "Unknown", double p = 0.01, int q = 0);

    void setCode(const std::string& c);
    void setName(const std::string& n);
    void setPrice(double p);
    void setQuantity(int q);

    std::string getCode() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    double calculateSum() const;
    operator std::string() const;

    friend std::istream& operator>>(std::istream& is, Goods& g);
    friend std::ostream& operator<<(std::ostream& os, const Goods& g);
};

#endif 