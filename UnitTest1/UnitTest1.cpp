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
            Goods g1("001", "Apple", 15.5, 2);
            Goods g2("002", "Bread", 20.0, 1);

            Receipt r("12345", "02.04.2026", "15:30");

            r.addGoods(g1);
            r.addGoods(g2);

            double expectedTotal = 51.0;
            Assert::AreEqual(expectedTotal, r.calculateTotalSum(), 0.001);

            Goods found = r.searchByCode("001");
            Assert::AreEqual(string("Apple"), found.getName());
            Assert::AreEqual(15.5, found.getPrice(), 0.001);

            r.deleteGoods(0);

            double expectedTotalAfterDelete = 20.0;
            Assert::AreEqual(expectedTotalAfterDelete, r.calculateTotalSum(), 0.001);

            Goods remaining = r.searchByCode("002");
            Assert::AreEqual(string("Bread"), remaining.getName());
        }
	};
}
