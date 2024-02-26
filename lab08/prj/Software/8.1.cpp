#include <cmath> // Підключаємо бібліотеку cmath для використання математичних функцій
#include <iostream> // Підключаємо бібліотеку iostream для вводу/виводу
#include <windows.h> // Підключає мову

// Функція для обчислення виразу
double calculateS(double x, double y, double z) {
    // Обчислюємо вираз за формулою
    double S = (sin(x) / sqrt((y*z) / (x+y))) + 3 * pow(y, 5);
    return S; // Повертаємо результат
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //встановили шифрування
    double x, y, z; // Оголошуємо змінні x, y, z

    // Запитуємо у користувача ввести значення x, y, z
    std::cout << "Введіть значення x, y, z: ";
    std::cin >> x >> y >> z;

    // Обчислюємо S за допомогою функції calculateS
    double S = calculateS(x, y, z);

    // Виводимо результат
    std::cout << "Результат: " << S << std::endl;

    return 0; // Завершуємо програму
}

