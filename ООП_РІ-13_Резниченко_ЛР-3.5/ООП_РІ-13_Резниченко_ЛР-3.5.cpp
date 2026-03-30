#include <iostream>
#include "Goods.h"
#include "Receipt.h"

using namespace std;

int main() {
    cout << "--- Goods Class Demonstration ---" << endl;
    Goods milk("M001", "Milk", 35.50, 2);
    Goods bread("B001", "Bread", 20.00, 1);
    cout << "Created product: " << string(milk) << endl;

    cout << "\n--- Receipt Class Demonstration ---" << endl;
    Receipt* myReceipt = new Receipt("CHK-100", "28.10.2023 15:30");
    myReceipt->addGoods(milk);
    myReceipt->addGoods(bread);

    cout << *myReceipt << endl;

    cout << "\nModifying bread..." << endl;
    Goods newBread("B001", "Fresh_Bread", 22.00, 3);
    myReceipt->modifyGoods("B001", newBread);

    cout << *myReceipt << endl;

    delete myReceipt;

    cout << "\n--- Arrays of Objects ---" << endl;

    Receipt* arrReceipts = new Receipt[2];

    arrReceipts[0].setReceiptNumber("ARR-01");
    arrReceipts[0].addGoods(Goods("C001", "Coffee", 120.00, 1));

    arrReceipts[1] = arrReceipts[0];
    arrReceipts[1].setReceiptNumber("ARR-02");

    cout << "Copy (ARR-02): \n" << arrReceipts[1] << endl;

    delete[] arrReceipts;

    return 0;
}