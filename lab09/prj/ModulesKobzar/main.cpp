#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <limits>
#include <cfloat>

//lab 8
int s_calculation(int x, int y, int z) {
    return x + y + z;
}


//lab 9.1
double calculateElectricityBill(double kWh) {
    double totalCost = 0.0;

    if (kWh <= 150) {
        totalCost = kWh * 0.3084;
    } else if (kWh <= 800) {
        totalCost = 150 * 0.3084 + (kWh - 150) * 0.4194;
    } else {
        totalCost = 150 * 0.3084 + 650 * 0.4194 + (kWh - 800) * 1.3404;
    }

    return totalCost;
}

//lab 9.2
void determineMinWindSpeedAndBofort() {
    system("chcp 1251");
    const int numReadings = 6;
    double windSpeed[numReadings];

    std::cout << "Введіть швидкість вітру (в м/сек) о 00:00, 04:00, 8:00, 12:00, 16:00, 20:00:" << std::endl;
    for (int i = 0; i < numReadings; ++i) {
        std::cout << "Час " << i * 4 << ":00: ";
        std::cin >> windSpeed[i];
    }

    double minWindSpeed = DBL_MAX;
    int minBofort = -1;  // Індикатор для мінімального Бофорта

    const int numRanges = 13;
    const double windSpeedRanges[numRanges][2] = {
        {0.0, 0.5},
        {0.6, 1.5},
        {1.6, 3.3},
        {3.4, 5.4},
        {5.5, 7.9},
        {8.0, 10.7},
        {10.8, 13.8},
        {13.9, 17.1},
        {17.2, 20.7},
        {20.8, 24.4},
        {24.5, 28.4},
        {28.5, 32.6},
        {32.7, DBL_MAX}
    };

    for (int i = 0; i < numReadings; ++i) {
        for (int j = 0; j < numRanges; ++j) {
            if (windSpeed[i] >= windSpeedRanges[j][0] && windSpeed[i] <= windSpeedRanges[j][1]) {
                if (windSpeedRanges[j][0] < minWindSpeed) {
                    minWindSpeed = windSpeedRanges[j][0];
                    minBofort = j;
                }
                break;
            }
        }
    }

    std::cout << "Мінімальна швидкість вітру: " << minWindSpeed << " м/сек" << std::endl;
    std::cout << "Відповідний рівень Бофорта: " << minBofort << std::endl;
}


//lab 9.3
#include <iostream>
#include <bitset>

int countZerosOrOnes(int num, bool countZeros) {
    std::bitset<32> bits(num);

    return countZeros ? bits.count() : (32 - bits.count());
}

int main() {
    system ("chcp 1251");
    int number;
    std::cout << "Введіть натуральне число від 0 до 500700: ";
    std::cin >> number;

    if (number < 0 || number > 500700) {
        std::cerr << "Некоректне число! Введіть число від 0 до 500700." << std::endl;
        return 1; // Повертаємо код помилки
    }

    bool bitD = (number & (1 << 3)) != 0;

    int result = bitD ? countZerosOrOnes(number, true) : countZerosOrOnes(number, false);

    std::cout << "Результат: " << result << std::endl;

    return 0;
}


