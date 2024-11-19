#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_11_3/lab_11_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestPrintAll)
		{
			const std::string testFile = "testfile.txt";

			// Створюємо тестовий файл із відомим вмістом
			std::ofstream fout(testFile);
			fout << "============================================================================================" << std::endl;
			fout << "| Назва товару    | Назва магазину   | Вартість одиниці | Кількість   | Одиниця вимірювання|" << std::endl;
			fout << "============================================================================================" << std::endl;
			fout << "| Apple             | Supermarket      |         20.50 |          10 |                 kg |" << std::endl;
			fout.close();

			// Перехоплюємо вивід функції printAll
			std::streambuf* oldCout = std::cout.rdbuf(); // Зберігаємо стандартний вивід
			std::ostringstream outputMock;              // Потік для перехоплення
			std::cout.rdbuf(outputMock.rdbuf());        // Перенаправляємо вивід

			// Викликаємо функцію
			printAll(testFile);

			// Відновлюємо стандартний вивід
			std::cout.rdbuf(oldCout);

			// Отримуємо вивід функції
			std::string output = outputMock.str();

			// Перевіряємо, чи у виводі є очікувані рядки
			Assert::IsTrue(output.find("Apple") != std::string::npos); // Перевіряємо наявність "Apple"
			Assert::IsTrue(output.find("Supermarket") != std::string::npos); // Перевіряємо "Supermarket"
			Assert::IsTrue(output.find("20.50") != std::string::npos); // Перевіряємо "20.50"
			Assert::IsTrue(output.find("10") != std::string::npos); // Перевіряємо "10"
			Assert::IsTrue(output.find("kg") != std::string::npos); // Перевіряємо "kg"
		}
	};
}
