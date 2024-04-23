#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <locale> // Для використання локалізації українською мовою

using namespace std;

int main() {
    system("chcp 1251");
    cout << "----------------------------------\n"
         << "|          Kobzar Mykola ®       |\n"
         << "|ЦНТУ,Кропивницький,Україна, 2024|\n"
         << "----------------------------------\n";

    time_t rawtime;
    time(&rawtime);
    cout << ctime(&rawtime);

    // Встановлюємо українську локаль
    setlocale(LC_ALL, "uk_UA.utf8");

    ifstream inputFile("input_1.txt");

    if (!inputFile) {
        cerr << "Не вдалося відкрити вхідний файл.\n";
        return 1;
    }

    string inputText;
    string line;
    while (getline(inputFile, line)) {
        inputText += line + "\n";
    }

    inputFile.close();

    int lowercaseCount = 0;
    int uppercaseCount = 0;

    // Пошук і підрахунок літер у тексті
    for (char c : inputText) {
        if (iswlower(c)) {
            lowercaseCount++;
        } else if (iswupper(c)) {
            uppercaseCount++;
        }
    }

    cout << "Кількість символів нижнього регістра: " << lowercaseCount << endl;
    cout << "Кількість символів верхнього регістра: " << uppercaseCount << endl;

    string poem = "У сонячній хаті промінь косо Лежить криво на підлозі... Твої чорні шовкові волосся Вже посипані сивиною.";
    string wordToCheck = "підлозі";
    if (poem.find(wordToCheck) != string::npos) {
        cout << "Слово '" << wordToCheck << "' є у вірші.\n";
    } else {
        cout << "Слово '" << wordToCheck << "' не є у вірші.\n";
    }

    return 0;
}
