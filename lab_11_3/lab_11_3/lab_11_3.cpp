// lab_11_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

// Функція для створення заголовка таблиці в файлі
void createTableHeader(const string& filename) {
    ofstream fout(filename, ios::app);
    if (!fout) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }

    fout << "============================================================================================" << endl;
    fout << "| Назва товару    | Назва магазину   | Вартість одиниці | Кількість   | Одиниця вимірювання|" << endl;
    fout << "============================================================================================" << endl;

    fout.close();
}

// Функція для додавання товару
void addProduct(const string& filename) {
    string name, storeName, unit;
    double price;
    int quantity;

    cout << "Додавання товару:" << endl;
    cout << "Назва товару: ";
    cin >> name;
    cout << "Назва магазину: ";
    cin >> storeName;
    cout << "Вартість одиниці товару (грн): ";
    cin >> price;
    cout << "Кількість товару: ";
    cin >> quantity;
    cout << "Одиниця вимірювання: ";
    cin >> unit;

    ofstream fout(filename, ios::app); // Відкриваємо файл для дозапису
    if (!fout) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }

    fout << "| " << setw(15) << name
        << " | " << setw(16) << storeName
        << " | " << setw(16) << price
        << " | " << setw(11) << quantity
        << " | " << setw(18) << unit << " |" << endl;

    fout.close();
    cout << "Товар успішно додано!" << endl;
}

// Функція для виведення всіх товарів
void printAll(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    cout << "============================================================================================" << endl;
    fin.close();
}

// Функція для пошуку товарів за назвою
void printByName(const string& filename) {
    string inputName;
    cout << "Введіть назву товару для виведення: ";
    cin >> inputName;

    ifstream fin(filename);
    if (!fin) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    bool found = false;
    string line;
    cout << "============================================================================================" << endl;
    while (getline(fin, line)) {
        if (line.find(inputName) != string::npos) { // Перевіряємо, чи рядок містить назву товару
            cout << line << endl;
            found = true;
        }
    }
    cout << "============================================================================================" << endl;

    if (!found) {
        cout << "Товар не знайдено." << endl;
    }

    fin.close();
}

// Функція для пошуку товарів за назвою магазину
void printByStore(const string& filename) {
    string inputStore;
    cout << "Введіть назву магазину для виведення товарів: ";
    cin >> inputStore;

    ifstream fin(filename);
    if (!fin) {
        cout << "Не вдалося відкрити файл." << endl;
        return;
    }

    bool found = false;
    string line;
    cout << "============================================================================================" << endl;
    while (getline(fin, line)) {
        if (line.find(inputStore) != string::npos) { // Перевіряємо, чи рядок містить назву магазину
            cout << line << endl;
            found = true;
        }
    }
    cout << "============================================================================================" << endl;

    if (!found) {
        cout << "Товари з таким магазином не знайдено." << endl;
    }

    fin.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "f.txt"; // Ім'я файлу

    // Створюємо заголовок таблиці, якщо файл порожній
    ifstream checkFile(filename);
    if (!checkFile || checkFile.peek() == EOF) {
        createTableHeader(filename);
    }
    checkFile.close();

    int menuItem;
    do {
        cout << "\nВиберіть дію:" << endl;
        cout << " [1] - додати товар" << endl;
        cout << " [2] - вивести всі товари" << endl;
        cout << " [3] - вивести товар за назвою" << endl;
        cout << " [4] - вивести товари за магазином" << endl;
        cout << " [0] - вихід" << endl;
        cout << "Введіть значення: ";
        cin >> menuItem;

        switch (menuItem) {
        case 1:
            addProduct(filename);
            break;
        case 2:
            printAll(filename);
            break;
        case 3:
            printByName(filename);
            break;
        case 4:
            printByStore(filename);
            break;
        case 0:
            cout << "Завершення програми." << endl;
            break;
        default:
            cout << "Неправильний вибір! Спробуйте ще раз." << endl;
            break;
        }
    } while (menuItem != 0);

    return 0;
}



