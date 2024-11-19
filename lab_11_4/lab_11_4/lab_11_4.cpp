// lab_11_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>  // Для встановлення кодування
using namespace std;

void SetConsoleEncoding() {
    SetConsoleCP(1251);    // Встановлюємо кодування для вводу
    SetConsoleOutputCP(1251);  // Встановлюємо кодування для виводу
}

// Функція для визначення кількості рядків файлу
int CountLines(char* fname) {
    ifstream fin(fname);
    string line;
    int lineCount = 0;
    while (getline(fin, line)) {
        lineCount++;
    }
    return lineCount;
}

// Функція для визначення максимальної довжини рядка
int MaxLineLength(char* fname) {
    ifstream fin(fname);
    string line;
    int maxLength = 0;
    while (getline(fin, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }
    return maxLength;
}

// Функція для визначення кількості порожніх рядків
int CountEmptyLines(char* fname) {
    ifstream fin(fname);
    string line;
    int emptyLines = 0;
    while (getline(fin, line)) {
        if (line.empty()) {
            emptyLines++;
        }
    }
    return emptyLines;
}

// Функція для знаходження рядка, що починається і завершується заданими символами
string FindSpecialLine(char* fname, char startChar, char endChar) {
    ifstream fin(fname); // Відкриваємо файл для читання
    if (!fin.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return "";
    }

    string line;
    while (getline(fin, line)) { // Читаємо файл по рядках
        if (!line.empty() && line[0] == startChar && line[line.length() - 1] == endChar) {
            fin.close(); // Закриваємо файл після знаходження відповідного рядка
            return line; // Повертаємо рядок, що починається і завершується на задані символи
        }
    }

    fin.close(); // Якщо не знайшли, закриваємо файл
    return ""; // Повертаємо порожній рядок, якщо не знайшли
}


// Функція для аналізу текстового файлу та запису результатів
void AnalyzeTXT(char* fname, char* resultFileName) {
    ifstream fin(fname);  // відкрили файл для зчитування
    ofstream fout(resultFileName); // відкрили файл для запису результатів

    int lineCount = CountLines(fname);  // Кількість рядків
    int maxLength = MaxLineLength(fname);  // Максимальна довжина рядка
    int emptyLines = CountEmptyLines(fname);  // Кількість порожніх рядків

    char startChar, endChar;
    cout << "Введіть символ на початку рядка: ";
    cin >> startChar;
    cout << "Введіть символ на кінці рядка: ";
    cin >> endChar;
    string specialLine = FindSpecialLine(fname, startChar, endChar);  // Рядок, що починається і завершується заданими символами

    // Запис результатів у новий файл
    fout << "Кількість рядків: " << lineCount << endl;
    fout << "Максимальна довжина рядка: " << maxLength << endl;
    fout << "Кількість порожніх рядків: " << emptyLines << endl;
    fout << "Рядок, що починається з '" << startChar << "' і завершується на '" << endChar << "': " << specialLine << endl;

    fin.close();
    fout.close();
}

void CreateTXT(char* fname) {
    ofstream fout(fname); // відкрили файл для запису
    char ch; // відповідь користувача – чи продовжувати введення
    string s; // введений користувачем рядок
    do {
        cin.ignore(); // очищуємо буфер клавіатури
        cout << "Введіть рядок: ";
        getline(cin, s); // ввели рядок
        fout << s << endl; // записали його у файл
        cout << "Продовжити введення? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void PrintTXT(char* fname) {
    ifstream fin(fname); // відкрили файл для зчитування
    string s;
    cout << "Вміст файлу " << fname << ":" << endl;
    while (getline(fin, s)) { // поки можна прочитати рядок
        cout << s << endl; // виводимо його на екран
    }
    cout << endl;
}

int main() {
    SetConsoleEncoding();  // Встановлення кодування для консольного вводу/виводу

    int menuItem;
    char fname[100], resultFileName[100];

    do {
        cout << "Меню:" << endl;
        cout << "[1] - Створити текстовий файл з введених рядків" << endl;
        cout << "[2] - Проаналізувати текстовий файл" << endl;
        cout << "[3] - Вивести вміст текстового файлу" << endl;
        cout << "[0] - Вихід" << endl;
        cout << "Введіть номер опції: ";
        cin >> menuItem;

        switch (menuItem) {
        case 1:
            cout << "Введіть ім'я файлу для створення: ";
            cin >> fname;
            CreateTXT(fname);
            break;
        case 2:
            cout << "Введіть ім'я файлу для аналізу: ";
            cin >> fname;
            cout << "Введіть ім'я файлу для запису результатів: ";
            cin >> resultFileName;
            AnalyzeTXT(fname, resultFileName);
            break;
        case 3:
            cout << "Введіть ім'я файлу для виведення: ";
            cin >> fname;
            PrintTXT(fname);
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    } while (menuItem != 0);

    return 0;
}














/*
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>  // Для встановлення кодування
using namespace std;

void SetConsoleEncoding() {
    SetConsoleCP(1251);    // Встановлюємо кодування для вводу
    SetConsoleOutputCP(1251);  // Встановлюємо кодування для виводу
}

// Функція для визначення кількості рядків файлу
int CountLines(char* fname) {
    ifstream fin(fname);
    string line;
    int lineCount = 0;
    while (getline(fin, line)) {
        lineCount++;
    }
    return lineCount;
}

// Функція для визначення максимальної довжини рядка
int MaxLineLength(char* fname) {
    ifstream fin(fname);
    string line;
    int maxLength = 0;
    while (getline(fin, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }
    return maxLength;
}

// Функція для визначення кількості порожніх рядків
int CountEmptyLines(char* fname) {
    ifstream fin(fname);
    string line;
    int emptyLines = 0;
    while (getline(fin, line)) {
        if (line.empty()) {
            emptyLines++;
        }
    }
    return emptyLines;
}

// Функція для знаходження рядка, що починається і завершується заданими символами
string FindSpecialLine(char* fname, char startChar, char endChar) {
    ifstream fin(fname);
    string line;
    string specialLine = "";
    while (getline(fin, line)) {
        if (line.front() == startChar && line.back() == endChar) {
            specialLine = line;
            break;
        }
    }
    return specialLine;
}

// Функція для аналізу текстового файлу та запису результатів
void AnalyzeTXT(char* fname, char* resultFileName) {
    ifstream fin(fname);  // відкрили файл для зчитування
    ofstream fout(resultFileName); // відкрили файл для запису результатів

    int lineCount = CountLines(fname);  // Кількість рядків
    int maxLength = MaxLineLength(fname);  // Максимальна довжина рядка
    int emptyLines = CountEmptyLines(fname);  // Кількість порожніх рядків

    char startChar, endChar;
    cout << "Введіть символ на початку рядка: ";
    cin >> startChar;
    cout << "Введіть символ на кінці рядка: ";
    cin >> endChar;
    string specialLine = FindSpecialLine(fname, startChar, endChar);  // Рядок, що починається і завершується заданими символами

    // Запис результатів у новий файл
    fout << "Кількість рядків: " << lineCount << endl;
    fout << "Максимальна довжина рядка: " << maxLength << endl;
    fout << "Кількість порожніх рядків: " << emptyLines << endl;
    fout << "Рядок, що починається з '" << startChar << "' і завершується на '" << endChar << "': " << specialLine << endl;

    fin.close();
    fout.close();
}

void CreateTXT(char* fname) {
    ofstream fout(fname); // відкрили файл для запису
    char ch; // відповідь користувача – чи продовжувати введення
    string s; // введений користувачем рядок
    do {
        cin.ignore(); // очищуємо буфер клавіатури
        cout << "Введіть рядок: ";
        getline(cin, s); // ввели рядок
        fout << s << endl; // записали його у файл
        cout << "Продовжити введення? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void PrintTXT(char* fname) {
    ifstream fin(fname); // відкрили файл для зчитування
    string s;
    cout << "Вміст файлу " << fname << ":" << endl;
    while (getline(fin, s)) { // поки можна прочитати рядок
        cout << s << endl; // виводимо його на екран
    }
    cout << endl;
}

int main() {
    SetConsoleEncoding();  // Встановлення кодування для консольного вводу/виводу

    int menuItem;
    char fname[100], resultFileName[100];

    do {
        cout << "Меню:" << endl;
        cout << "[1] - Створити текстовий файл з введених рядків" << endl;
        cout << "[2] - Проаналізувати текстовий файл" << endl;
        cout << "[3] - Вивести вміст текстового файлу" << endl;
        cout << "[0] - Вихід" << endl;
        cout << "Введіть номер опції: ";
        cin >> menuItem;

        switch (menuItem) {
        case 1:
            cout << "Введіть ім'я файлу для створення: ";
            cin >> fname;
            CreateTXT(fname);
            break;
        case 2:
            cout << "Введіть ім'я файлу для аналізу: ";
            cin >> fname;
            cout << "Введіть ім'я файлу для запису результатів: ";
            cin >> resultFileName;
            AnalyzeTXT(fname, resultFileName);
            break;
        case 3:
            cout << "Введіть ім'я файлу для виведення: ";
            cin >> fname;
            PrintTXT(fname);
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    } while (menuItem != 0);

    return 0;
}




*/