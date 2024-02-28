#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "ModulesKobzar.h"

int s_calculation(int x, int y, int z) {
    return x + y + z;
}

void printDeveloperInfo() {
    using namespace std;
    system("chcp 1251");
    cout << "-----------------\n"
         << "|Kobzar Mykola ®|\n"
         << "-----------------\n";

}

void printLogicalExpressionResult(int a, int b) {
    bool result = a + 1 < b + 3;
    std::cout << "Результат логічного виразу: " << result << "\n";
}

void printValuesAndCalculation(int x, int y, int z) {
    std::cout << "Значення x, y, z у десятковій системі числення: " << x << ", " << y << ", " << z << "\n";
    int s = s_calculation(x, y, z);
    std::cout << "S : " << s << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x, y, z;
    int a, b;

    std::cout << "Введіть значення x, y, z, a, b:\n";
    std::cin >> x >> y >> z >> a >> b;

    printDeveloperInfo();
    printLogicalExpressionResult(a, b);
    printValuesAndCalculation(x, y, z);

    return 0;
}
