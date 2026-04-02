#include "Receipt.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "--- Testing Goods Class ---" << endl;
    Goods g1;
    cout << "Enter Goods details (Code Name Price Quantity):" << endl;
    cin >> g1;

    cout << "\nTesting Getters for Goods:" << endl;
    cout << "Code: " << g1.getCode() << "" << endl;
    cout << "Name: " << g1.getName() << "" << endl;
    cout << "Price: " << g1.getPrice() << "" << endl;
    cout << "Quantity: " << g1.getQuantity() << "" << endl;
    cout << "Total Sum: " << g1.calculateTotal() << "" << endl;

    cout << "\nTesting Setters for Goods:" << endl;
    g1.setName("SuperApple");
    g1.setPrice(12.5);
    g1.setQuantity(5);
    cout << "Updated Goods: " << string(g1) << "" << endl;

    cout << "\n--- Testing Array Class (via Receipt) ---" << endl;
    Receipt r1;
    cout << "Enter Receipt details (ReceiptNumber Date Time NumberOfItems) and then the items:" << endl;
    cin >> r1;

    cout << "\nTesting Output for Receipt:" << endl;
    cout << r1;

    cout << "\nTesting Setters for Receipt:" << endl;
    r1.setReceiptNumber("999");
    r1.setDate("01.01.2026");
    r1.setTime("12:00");
    cout << r1;

    cout << "\nTesting Array indexing (operator[]):" << endl;
    cout << "First item: " << string(r1[0]) << "" << endl;

    cout << "\nTesting Add, Change, Delete, Search:" << endl;
    Goods g2("002", "Banana", 30.0, 2);
    r1.addGoods(g2);
    cout << "After Addition:\n" << r1;

    Goods g3("003", "Orange", 40.0, 1);
    r1.changeGoods(0, g3);
    cout << "After Change:\n" << r1;

    r1.deleteGoods(1);
    cout << "After Deletion:\n" << r1;

    Goods found = r1.searchByCode("003");
    cout << "Search result: " << string(found) << "" << endl;

    cout << "\n--- Testing Assignment and Array of Objects ---" << endl;
    Receipt r2;
    r2 = r1;
    cout << "Assigned Receipt:\n" << r2;

    Receipt arr[2];
    arr[0] = r1;
    arr[1] = r2;

    cout << "\nArray of Receipts initialized successfully." << endl;

    return 0;
}