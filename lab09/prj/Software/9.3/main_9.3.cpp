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

