#include <iostream>
#include <fstream>
#include <ctime>
#include <locale>
#include <cctype>

using namespace std;

// Функція для зміни регістру символів
string reverseCase(const string& str) {
    string result;
    for (char c : str) {
        if (isupper(c))
            result += tolower(c);
        else if (islower(c))
            result += toupper(c);
        else
            result += c;
    }
    return result;
}

int main() {
    system("chcp 1251");
    cout << "----------------------------------\n"
         << "|          Kobzar Mykola ®       |\n"
         << "|ЦНТУ,Кропивницький,Україна, 2024|\n"
         << "----------------------------------\n";

    // Отримання поточного часу
    time_t rawtime;
    time(&rawtime);

    // Виведення поточного часу
    cout << ctime(&rawtime);

    // Читання вхідного файлу
    ifstream input("input_2.txt");
    if (!input.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    // Пошук та аналіз слова "Chandelier"
    string word;
    while (input >> word) {
        if (word == "Chandelier") {
            int upperCount = 0, lowerCount = 0;
            for (char c : word) {
                if (isupper(c))
                    upperCount++;
                else if (islower(c))
                    lowerCount++;
            }
            // Виведення результатів в консоль
            cout << "Слово: " << word << endl;
            cout << "Кількість символів верхнього регістру: " << upperCount << endl;
            cout << "Кількість символів нижнього регістру: " << lowerCount << endl;

            // Перетворення регістру і виведення результатів
            string reversedWord = reverseCase(word);
            cout << "Слово зі зміненим регістром: " << reversedWord << endl;
            int reversedUpperCount = 0, reversedLowerCount = 0;
            for (char c : reversedWord) {
                if (isupper(c))
                    reversedUpperCount++;
                else if (islower(c))
                    reversedLowerCount++;
            }
            cout << "Кількість символів верхнього регістру після зміни: " << reversedUpperCount << endl;
            cout << "Кількість символів нижнього регістру після зміни: " << reversedLowerCount << endl;
            break; // Якщо слово знайдено, можна припинити читання файлу
        }
    }

    // Закриття файлу
    input.close();

    return 0;
}
