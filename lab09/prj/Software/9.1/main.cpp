#include <iostream>
#include "ModulesKobzar.h"
#include <stdio.h>

double s_calculate(double consumed_energy) {
    const double tariff_1 = 0.3084;  // 30.84 ���. / ������
    const double tariff_2 = 0.4194;  // 41.94 ���. / ������
    const double tariff_3 = 1.3404;  // 134.04 ���. / ������

    double total_payment = 0.0;

    if (consumed_energy <= 150) {
        total_payment = consumed_energy * tariff_1;
    } else if (consumed_energy <= 800) {
        total_payment = 150 * tariff_1 + (consumed_energy - 150) * tariff_2;
    } else {
        total_payment = 150 * tariff_1 + 650 * tariff_2 + (consumed_energy - 800) * tariff_3;
    }

    return total_payment;
}

int main() {
    using namespace std;
    system("chcp 1251");
    double consumed_energy;
    std::cout << "������ ������� ������� �����������㳿 (������): ";
    std::cin >> consumed_energy;

    double total_payment = s_calculate(consumed_energy);

    std::cout << "���� �� ������: " << total_payment << " �������." << std::endl;

    return 0;
}
