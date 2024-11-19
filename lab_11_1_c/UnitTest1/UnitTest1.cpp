#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_11_1_c/lab_11_1_c.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_CountOccurrences)
		{
			// Тестируем функцию CountOccurrences

			// Тестовые данные
			char text1[] = "while loop while another while";
			char substring1[] = "while";

			// Ожидаем 3 вхождения
			Assert::AreEqual(3, CountOccurrences(text1, substring1));
		}
	};
}