#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_11_4/lab_11_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCountLines)
        {
            // Створимо тестовий файл
            const char* fname = "test.txt";
            std::ofstream fout(fname);
            fout << "First line" << std::endl;
            fout << "Second line" << std::endl;
            fout << "Third line" << std::endl;
            fout.close();

            // Перевіряємо, чи правильно рахується кількість рядків
            int result = CountLines((char*)fname);
            Assert::AreEqual(result, 3);

            // Видаляємо тестовий файл
            remove(fname);
        }
	};
}
