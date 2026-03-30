#ifndef RECEIPT_H
#define RECEIPT_H

#include "Array.h"
#include "Goods.h"
#include <string>

class Receipt : public Array<Goods> {
private:
    std::string receiptNumber;
    std::string dateTime;

public:
    Receipt(std::string number = "000000", std::string dt = "01.01.1970 00:00");

    void setReceiptNumber(const std::string& number);
    void setDateTime(const std::string& dt);

    void addGoods(const Goods& g);
    void removeGoods(const std::string& code);
    void modifyGoods(const std::string& code, const Goods& newGoods);
    Goods searchGoods(const std::string& code) const;
    double getTotalSum() const;

    operator std::string() const;

    friend std::istream& operator>>(std::istream& is, Receipt& r);
    friend std::ostream& operator<<(std::ostream& os, const Receipt& r);
};

#endif 