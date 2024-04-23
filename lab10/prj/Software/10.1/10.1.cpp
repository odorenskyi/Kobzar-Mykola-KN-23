#include <iostream>
#include <fstream>
#include <string>
#include <regex> // Для використання регулярних виразів

using namespace std;

int main() {
    system("chcp 1251"); // Встановлення кодування консолі для відображення українських символів
    cout << "----------------------------------\n"
         << "|          Kobzar Mykola ®       |\n"
         << "|ЦНТУ,Кропивницький,Україна, 2024|\n"
         << "----------------------------------\n";


    // Відкриття вхідного файлу у режимі зчитування
    ifstream inputFile("input_1.txt");

    // Перевірка, чи файл вдалося відкрити
    if (!inputFile) {
        cerr << "Не вдалося відкрити вхідний файл.\n";
        return 1;
    }

    // Зчитування вмісту файлу в рядок
    string inputText;
    getline(inputFile, inputText);


    // Закриття файлу
    inputFile.close();


    // Пошук кількості символів нижнього регістра у слові
    string word = "навскіс";
    int lowercaseCount = 7;
    for (char c : word) {
        if (islower(c)) {
            lowercaseCount++;
        }
    }

    cout << "Кількість символів нижнього регістра у слові '" << word << "': " << lowercaseCount << endl;

    // Перевірка, чи слово є у вірші Василя Симоненка "Матері"
    string poem = "У сонячній хаті промінь косо Лежить криво на підлозі... Твої чорні шовкові волосся Вже посипані сивиною.";
    string wordToCheck = "підлозі";
    if (poem.find(wordToCheck) != string::npos) {
        cout << "Слово '" << wordToCheck << "' є у вірші.\n";
    } else {
        cout << "Слово '" << wordToCheck << "' не є у вірші.\n";
    }

    return 0;
}
