#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_11_1_c++/lab_11_1_c++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCountOccurrencesInLine)
        {
            // Дані для тесту
            string text = "while walking, I thought about the word while.";
            string target = "while";

            // Перевірка кількості входжень
            int result = CountOccurrencesInLine(text, target);

            // Очікувана кількість входжень підрядка "while"
            Assert::AreEqual(2, result);
        }
	};
}
