#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../lab_11_2/lab_11_2.cpp"  // Потрібно вказати правильний шлях до вашого файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест для функції CountAInLastWordInFile
        TEST_METHOD(TestCountAInLastWordInFile)
        {
            // Створюємо тимчасовий файл для тесту
            string filename = "test.txt";
            ofstream file(filename);  // Відкриваємо файл для запису

            // Перевірка на успішне відкриття файлу
            if (!file.is_open()) {
                Assert::Fail(L"Could not create or open file for writing.");
            }

            // Записуємо тестові дані у файл
            file << "banana apple\n";  // Літера 'a' в останньому слові "apple"
            file << "hello world\n";   // Літера 'a' в останньому слові "world" немає
            file << "aaa bbb aaa\n";   // Літера 'a' в останньому слові "aaa"
            file.close();

            // Створюємо змінну для останнього слова
            string lastWord;

            // Викликаємо функцію, щоб підрахувати кількість 'a' в останньому слові кожного рядка
            int count = CountAInLastWordInFile(filename, lastWord);

            // Перевірка: очікуємо, що кількість літер 'a' = 1 (з "apple") + 0 (з "world") + 3 (з "aaa") = 4
            Assert::AreEqual(count, 4, L"Number of 'a' in last words should be 4");

            // Видаляємо тимчасовий файл після тесту
            remove(filename.c_str());
        }
    };
}
