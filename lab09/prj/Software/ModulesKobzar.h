#ifndef S_CALCULATOR_H
#define S_CALCULATOR_H

class SCalculator {
public:
    static double calculate(double x, double y, double z);
};

#endif //

#include <bitset>

// Функція для підрахунку кількості двійкових нулів або одиниць у числі
int countZerosOrOnes(int num, bool countZeros) {
    std::bitset<32> bits(num); // Перетворюємо число в бінарний формат

    // Використовуємо тернарний оператор для підрахунку нулів або одиниць
    return countZeros ? bits.count() : (32 - bits.count());
}


