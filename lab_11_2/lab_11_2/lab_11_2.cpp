// lab_11_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функція для пошуку останнього слова в рядку та підрахунку літер 'a'
size_t CountAInLastWord(const string& s, string& lastWord)
{
    size_t lastSpace = s.find_last_not_of(" "); // останній символ, що не є пробілом
    size_t wordStart = s.find_last_of(" ", lastSpace); // пробіл і початок останнього слова
    lastWord = s.substr(wordStart + 1, lastSpace - wordStart); // отримаємо саме слово

    int countA = 0;
    for (int i = 0; i < lastWord.length(); i++) // довжина
    {
        if (lastWord[i] == 'a')
            countA++;
    }
    return countA;
}

// Функція для обробки файлу та підрахунку кількості літер 'a' в останньому слові
int CountAInLastWordInFile(const string& filename, string &lastWord)
{
    ifstream file(filename); // відкриваємо файл
    if (!file.is_open()) // перевірка на успішне відкриття файлу
    {
        cerr << "Error: Cannot open file " << filename << endl;
        return -1; // якщо файл не відкрився, повертаємо помилку
    }

    string line;
    
    int totalCount = 0;

    // Читаємо файл рядок за рядком
    while (getline(file, line))
    {
        // Для кожного рядка підраховуємо кількість літер 'a' в останньому слові
        totalCount += CountAInLastWord(line, lastWord);
    }

    file.close(); // закриваємо файл
    return totalCount;
}

int main()
{
    string filename = "f.txt"; // ім'я файлу
    string lastWord;
    int count = CountAInLastWordInFile(filename, lastWord); // викликаємо функцію для обробки файлу
    if (count != -1)
    {
        cout << "Total number of 'a' letters in the last word of each line: " << count <<"  in"<< lastWord << endl;
    }

    return 0;
}
