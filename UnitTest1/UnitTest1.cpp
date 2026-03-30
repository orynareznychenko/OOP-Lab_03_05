#include "pch.h"
#include "CppUnitTest.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.5/Array.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.5/Goods.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.5/Receipt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            std::string expectedCode = "T001";
            std::string expectedName = "Test_Apple";
            double price = 15.50;
            int quantity = 4;
            double expectedSum = 62.00; 

            Goods testItem(expectedCode, expectedName, price, quantity);

            Assert::AreEqual(expectedCode, testItem.getCode(), L"Код товару не співпадає!");
            Assert::AreEqual(expectedName, testItem.getName(), L"Назва товару не співпадає!");
            Assert::AreEqual(price, testItem.getPrice(), L"Ціна товару не співпадає!");
            Assert::AreEqual(quantity, testItem.getQuantity(), L"Кількість товару не співпадає!");

            Assert::AreEqual(expectedSum, testItem.calculateSum(), L"Сума обчислена неправильно!");
		}
	};
}
