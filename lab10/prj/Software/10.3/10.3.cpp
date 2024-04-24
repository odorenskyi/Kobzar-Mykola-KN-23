#include <iostream>
#include <fstream> // Для роботи з файлами
#include <bitset>
#include "ModulesKobzar.h"

using namespace std; // Використання простору імен std

int main() {
    system("chcp 1251");
    double x, y, z;
    int b;

    // Зчитуємо значення x, y, z та b з консолі
    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть значення y: ";
    cin >> y;
    cout << "Введіть значення z: ";
    cin >> z;
    cout << "Введіть значення b: ";
    cin >> b;

    // Викликаємо функцію s_calculate з модуля ModulesKobzar
    double result = ModulesKobzar::s_calculate(x, y, z);

    // Відкриваємо файл "output.txt" для запису результатів
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        // Записуємо результат обчислень у файл
        outputFile << "Результат обчислень: " << result << endl;

        // Перетворюємо число b в двійковий код та записуємо результат у файл
        outputFile << "Число b у двійковому коді: " << bitset<sizeof(b) * 8>(b) << endl;

        // Закриваємо файл
        outputFile.close();

        cout << "Результати було успішно записано у файл 'output.txt'." << endl;
    } else {
        cout << "Помилка відкриття файлу 'output.txt'." << endl;
    }

    return 0;
}
