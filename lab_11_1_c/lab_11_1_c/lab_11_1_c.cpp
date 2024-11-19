// lab_11_1_c.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

// Функція для підрахунку кількості входжень підрядка в рядок
int CountOccurrences(const char* text, const char* substring) {
    int count = 0;
    const char* pos = text;

    // Використовуємо strstr для пошуку підрядка
    while ((pos = strstr(pos, substring)) != NULL) {
        count++;
        pos += strlen(substring); // Переміщуємо вказівник за знайдене входження
    }

    return count;
}

// Функція для обробки файлу та підрахунку входжень підрядка
int CountOccurrencesInFile(const char* fileName, const char* substring) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        cerr << "Помилка при відкритті файлу '" << fileName << "'." << endl;
        return -1;
    }

    char buffer[100]; // Буфер для читання рядків із файлу
    int totalCount = 0;

    // Читаємо файл построчно
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        totalCount += CountOccurrences(buffer, substring);
    }

    fclose(file);
    return totalCount;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char fileName[] = "1.txt"; // Ім'я файлу
    const char target[] = "while";   // Цільовий підрядок

    // Підраховуємо кількість входжень у файлі
    int occurrences = CountOccurrencesInFile(fileName, target);
    if (occurrences == -1) {
        return 1; // Помилка відкриття файлу
    }

    // Виводимо результат
    cout << "Файл '" << fileName << "' містить " << occurrences
        << " входжень підрядка '" << target << "'." << endl;

    return 0;
}