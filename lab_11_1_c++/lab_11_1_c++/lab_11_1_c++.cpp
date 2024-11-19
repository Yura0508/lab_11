// lab_11_1_c++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

int CountOccurrencesInLine(const string& text, const string& target)
{
    int count = 0;
    size_t targetLength = target.size(); // while 5 букв
    // Перевірка кожної позиції рядка
    for (size_t i = 0; i <= text.size() - targetLength; ++i) {
        bool match = true;
        for (size_t j = 0; j < targetLength; ++j){
            if (text[i + j] != target[j]){
                match = false;
                break;
            }
        }
        if (match){
            count++;
        }
    }
    return count;
}

// Функція для обробки файлу та підрахунку загальної кількості входжень
int CountOccurrencesInFile(const char* filename, const string& target)
{
    ifstream file(filename); // Відкриваємо файл
    if (!file.is_open())
    {
        cerr << "Error: Cannot open file " << filename << endl;
        return -1;
    }

    string line;
    int totalCount = 0;

    while (getline(file, line)) // Читаємо файл рядок за рядком
    {
        totalCount += CountOccurrencesInLine(line, target);
    }

    file.close(); // Закриваємо файл
    return totalCount;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char fname[] = "f.txt"; // Ім'я файлу
    const string target = "while"; // Цільовий підрядок

    int count = CountOccurrencesInFile(fname, target);
    if (count != -1)
    {
        cout << "Файл '" << fname << "' містить " << count << " входжень підрядка '" << target << "'." << endl;
    }

    return 0;
}



























/*
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

// Функція підрахунку входжень групи букв "while" у рядку
int CountOccurrences(const string& text, const string& target)
{
    size_t pos = 0;
    int count = 0;

    while ((pos = text.find(target, pos)) != string::npos)
    {
        count++;
        pos++; // Зсунути позицію вперед
    }

    return count;
}

// Функція для обробки файлу
int CountOccurrencesInFile(const string filename, const string& target)
{
    ifstream file(filename); // Відкриваємо файл для читання
    if (!file.is_open())
    {
        cerr << "Error: Cannot open file " << filename << endl;
        return -1;
    }

    string line;
    int totalCount = 0;

    // Читаємо файл рядок за рядком
    while (getline(file, line))
    {
        totalCount += CountOccurrences(line, target);
    }

    file.close(); // Закриваємо файл
    return totalCount;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char fname[] = "f.txt";             // Ім'я файлу
    const string target = "while"; // Цільова група букв

    int count = CountOccurrencesInFile(fname, target);
    if (count != -1)
    {
        cout << "Файл '" << fname << "' містить " << count << " входжень підрядка '" << target << "'." << endl;
    }

    return 0;
}

*/